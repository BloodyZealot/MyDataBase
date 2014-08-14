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
    public class ProduectList : IHttpHandler
    {

        public void ProcessRequest(HttpContext context)
        {

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