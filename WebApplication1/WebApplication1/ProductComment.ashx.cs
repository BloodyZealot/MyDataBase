using SqlHelper;
using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Web;
using System.Web.Script.Serialization;

namespace WebApplication1
{
    /// <summary>
    /// ProductComment 的摘要说明
    /// </summary>
    public class ProductComment : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {
            context.Response.ContentType = "text/plain";
            string action = context.Request["action"];
            int pid;
            DataTable table;
            pid = Convert.ToInt32(context.Request["id"]);
            switch (action)
            {
                case "post":
                    string title = context.Request["title"];
                    string msg = context.Request["msg"];
                    MySqlHelper.ExecuteNonQuery("insert into productcomment (ProductID,Title,Msg) " +
                                                                           "values (@pid,@title,@msg)",
                                                                           new MySql.Data.MySqlClient.MySqlParameter("@pid", pid),
                                                                           new MySql.Data.MySqlClient.MySqlParameter("@title", title),
                                                                           new MySql.Data.MySqlClient.MySqlParameter("@msg", msg));
                    break;
                case "get":
                default:
                    table = MySqlHelper.ExecuteDataTable("select * from productcomment where ProductID =@pid",
                                                                            new MySql.Data.MySqlClient.MySqlParameter("@pid", pid));
                    object[] comments = new object[table.Rows.Count];
                    for (int i = 0; i != table.Rows.Count; ++i)
                        comments[i] = new { Title = table.Rows[i]["title"], Msg = table.Rows[i]["msg"] };
                    string result = new JavaScriptSerializer().Serialize(comments);
                    context.Response.Write(result);
                    break;
            }
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