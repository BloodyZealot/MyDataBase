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
            string category = context.Request["category"];
            string limit="";
            DataTable table;
            if (!string.IsNullOrEmpty(category))
            {
                int cid = Convert.ToInt32(MySqlHelper.ExecuteScalar("select ID from productcategory " +
                                                                                                   "where Name=@name",
                                                           new MySql.Data.MySqlClient.MySqlParameter("@name", category)));
                if (cid != 0)
                    limit = " where products.CategoryID = " + cid;
                else
                    category = "";
            }
            else
                category = "";
            string snum = context.Request["page"];
            int pagenum;
            if (string.IsNullOrEmpty(snum))
                pagenum = 1;
            else
                pagenum = Convert.ToInt32(snum);
            int productnum = Convert.ToInt32(MySqlHelper.ExecuteScalar("select count(*) from products " + limit));
            int pagecount = (int)Math.Ceiling(productnum / 12.0);
            int[] array = new int[pagecount];
            for (int i = 0; i != pagecount; ++i)
                array[i] = i + 1;
            table = MySqlHelper.ExecuteDataTable("select products.*, productcategory.Name as 'CName' " +
                                                                                " from products join productcategory " +
                                                                                " on products.CategoryID=productcategory.ID " + limit +
                                                                                " order by products.ID limit @pagenum,12 ",
                                                     new MySql.Data.MySqlClient.MySqlParameter("@pagenum", (pagenum - 1) * 12));
            html = NVRender.ReanderHtml("products.html", new
                                                                                               {
                                                                                                   title = "产品展示",
                                                                                                   rows = table.Rows,
                                                                                                   array = array,
                                                                                                   currentpage = pagenum,
                                                                                                   maxpage = pagecount,
                                                                                                   productnum = productnum,
                                                                                                   category=category
                                                                                               });
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