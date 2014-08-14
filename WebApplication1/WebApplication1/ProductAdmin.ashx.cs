using Nvelocity;
using SqlHelper;
using System;
using System.Collections.Generic;
using System.Data;
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
            string html;
            switch (context.Request["action"])
            {
                case "edit":
                    int id=Convert.ToInt32(context.Request["id"]);
                    table = MySqlHelper.ExecuteDataTable("select * from products where id=@id",
                        new MySql.Data.MySqlClient.MySqlParameter("@id", id));
                    if (table.Rows.Count !=1)
                        html = "Error! You have make a worng request!";
                    else
                        html = NVRender.ReanderHtml("/admin/productedit.html", 
                            new { title = "edit product", product = table.Rows[0] });
                    break;
                default:
                    table = MySqlHelper.ExecuteDataTable("select * from products");
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