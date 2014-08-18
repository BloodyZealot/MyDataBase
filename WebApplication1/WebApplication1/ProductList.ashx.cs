using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using SqlHelper;
using Nvelocity;

namespace WebApplication1
{
    /// <summary>
    /// ProduectList 的摘要说明
    /// </summary>
    public class ProductList : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/html";
            string html;
            DataTable table;
            switch (context.Request["class"])
            {
                default:
                    table = MySqlHelper.ExecuteDataTable("select * from products");
                    break;
            }

            html = NVRender.ReanderHtml("products.html", new { title = "产品展示" ,rows=table.Rows });
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