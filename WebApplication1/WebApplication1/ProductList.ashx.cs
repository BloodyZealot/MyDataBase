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
            string limit = "";
            int listlength = 12;
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
            int pagecount = (int)Math.Ceiling(productnum / (listlength * 1.0));
            if (pagenum > pagecount)
                pagenum = 1;
            int starter = (pagenum - 1) / 10 * 10;
            int[] array = new int[pagecount - starter > 10 ? 10 : pagecount - starter];
            array[0] = starter + 1 ;
            for (int i = 1; i != array.Length; ++i)
                array[i] = array[i - 1] + 1;
            table = MySqlHelper.ExecuteDataTable("select products.*, productcategory.Name as 'CName' " +
                                                                                " from products join productcategory " +
                                                                                " on products.CategoryID=productcategory.ID " + limit +
                                                                                " order by products.ID limit @pagenum,@listlength ",
                                                     new MySql.Data.MySqlClient.MySqlParameter("@pagenum", (pagenum - 1) * listlength),
                                                     new MySql.Data.MySqlClient.MySqlParameter("@listlength",listlength));
            html = NVRender.ReanderHtml("products.html", new
                                                                                               {
                                                                                                   title = "产品展示",
                                                                                                   rows = table.Rows,
                                                                                                   array = array,
                                                                                                   currentpage = pagenum,
                                                                                                   maxpage = pagecount,
                                                                                                   productnum = productnum,
                                                                                                   category = category
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