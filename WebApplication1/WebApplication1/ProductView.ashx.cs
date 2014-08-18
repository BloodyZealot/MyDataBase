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
    /// ProductView 的摘要说明
    /// </summary>
    public class ProductView : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/html";
            string html;
            //TODO:Check The ID is Vaild or Not
            int id=0;
            try { id = Convert.ToInt32(context.Request["id"]); }
            catch(FormatException fe)
            {
                html = "您的链接有误，请检查您的链接后重试！";
            }
            DataTable table = MySqlHelper.ExecuteDataTable("select products.*, productcategory.Name as 'CName' " +
                                                                                               "from products join productcategory " +
                                                                                               "on products.CategoryID=productcategory.ID "+
                                                                                               "where products.ID=@id ",
                                                                                    new MySql.Data.MySqlClient.MySqlParameter("@id", id));
            if(table.Rows.Count!=1)
            {
                html = "您请求的产品不存在，请检查您的链接后重试！";
            }
            html = NVRender.ReanderHtml("view.html", new { title="产品详细",product=table.Rows[0]});
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