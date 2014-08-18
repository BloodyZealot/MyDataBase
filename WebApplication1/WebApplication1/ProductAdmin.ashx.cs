using Nvelocity;
using SqlHelper;
using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Web;

namespace WebApplication1
{
    /// <summary>
    /// ProductAdmin 的摘要说明
    /// </summary>
    public class ProductAdmin : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/html";
            DataTable table;
            string html = "";
            string name, msg, cid, imagename, path;
            int id;
            HttpPostedFile image;
            switch (context.Request["action"])
            {
                case "edit":
                    id = Convert.ToInt32(context.Request["id"]);
                    table = MySqlHelper.ExecuteDataTable("select * from products where id=@id",
                        new MySql.Data.MySqlClient.MySqlParameter("@id", id));
                    if (table.Rows.Count != 1)
                        html = "Error! You have make a worng request!";
                    else
                        html = NVRender.ReanderHtml("/admin/productedit.html",
                            new { title = "edit product", baseaction = "edit", product = table.Rows[0] });
                    break;
                case "editlaunch":
                    id = Convert.ToInt32(context.Request["productid"]);
                    name = context.Request["productname"];
                    msg = context.Request["productmsg"];
                    cid = context.Request["productcategoryid"];
                    image = context.Request.Files["productimage"];
                    if (image.FileName != "")
                    {
                        imagename = DateTime.Now.ToString("yyyymmddhhmmssffff") + Path.GetExtension(image.FileName);
                        path = context.Server.MapPath("~/uploadfile/");
                        image.SaveAs(path + imagename);
                        MySqlHelper.ExecuteNonQuery(@"update products set Name=@name,Msg=@msg,ImagePath=@image,CategoryID=@cid
                                                                                    where ID=@id",
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@id", id),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@name", name),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@msg", msg),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@image", "uploadfile/" + imagename),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@cid", Convert.ToInt32(cid)));
                    }
                    else
                    {
                        MySqlHelper.ExecuteNonQuery(@"update products set Name=@name,Msg=@msg,CategoryID=@cid
                                                                                    where ID=@id",
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@id", id),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@name", name),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@msg", msg),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@cid", Convert.ToInt32(cid)));
                    }
                    context.Response.Redirect("ProductAdmin.ashx");
                    break;
                case "add":
                    html = NVRender.ReanderHtml("/admin/productedit.html",
                            new { title = "add product", baseaction = "add", product = new { Name = "", Msg = "", CategoryID = "" } });
                    break;
                case "addlaunch":
                    name = context.Request["productname"];
                    msg = context.Request["productmsg"];
                    cid = context.Request["productcategoryid"];
                    image = context.Request.Files["productimage"];
                    imagename = DateTime.Now.ToString("yyyymmddhhmmssffff") + Path.GetExtension(image.FileName);
                    path = context.Server.MapPath("~/uploadfile/");
                    image.SaveAs(path + imagename);
                    MySqlHelper.ExecuteNonQuery(@"insert into products (Name,Msg,ImagePath,CategoryID) values
                                                                                (@name,@msg,@image,@cid)",
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@name", name),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@msg", msg),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@image", "uploadfile/" + imagename),
                                                                                new MySql.Data.MySqlClient.MySqlParameter("@cid", Convert.ToInt32(cid)));
                    context.Response.Redirect("ProductAdmin.ashx");
                    break;
                default:
                    table = MySqlHelper.ExecuteDataTable(@"select products.*, productcategory.Name as 'CName'
                                                                                        from products join productcategory
                                                                                        on products.CategoryID=productcategory.ID");
                    html = NVRender.ReanderHtml("/admin/productslist.html", new { rows = table.Rows, title = "list" });
                    break;
            }
            context.Response.Write(html);
        }

        public bool IsReusable
        {
            get
            {
                return false;
            }
        }
    }
}