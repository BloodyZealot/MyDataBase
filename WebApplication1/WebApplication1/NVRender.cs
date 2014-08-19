using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Data;
using System.Data.Common;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Configuration;
using NVelocity.App;
using NVelocity.Runtime;
using NVelocity;

namespace Nvelocity
{
    public static class NVRender
    {

        public static string ReanderHtml(string templateName, object data ,string rootName)
        {
            VelocityEngine vltEngine = new VelocityEngine();
            vltEngine.SetProperty(RuntimeConstants.RESOURCE_LOADER, "file");
            vltEngine.SetProperty(RuntimeConstants.FILE_RESOURCE_LOADER_PATH,
             System.Web.Hosting.HostingEnvironment.MapPath("~/template"));
            vltEngine.Init();

            VelocityContext vltContext = new VelocityContext();
            vltContext.Put(rootName, data);
            Template vltTemplate = vltEngine.GetTemplate(templateName);
            System.IO.StringWriter vltWriter = new System.IO.StringWriter();
            vltTemplate.Merge(vltContext, vltWriter);
            
            return vltWriter.GetStringBuilder().ToString();
        }
        public static string ReanderHtml(string templateName, object data)
        {
            return ReanderHtml(templateName, data, "data");
        }

    }
}