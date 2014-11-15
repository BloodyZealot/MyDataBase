using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace ConsoleApplication1
{
    class pat_1084
    {
        static void Main(string[] args)
        {
            string s1 = Console.ReadLine();
            string s2 = Console.ReadLine();
            String result="";
            int i, j;
            for (i = 0, j = 0; i != s1.Length&&j!=s2.Length; ++i)
            {
                if (s1[i] != s2[j])
                {
                    if (!result.Contains(char.ToUpper(s1[i])))
                        result += (char.ToUpper(s1[i]));
                }
                else
                    ++j;
            }
            for (; i != s1.Length; ++i)
                if (!result.Contains(char.ToUpper(s1[i])))
                    result += (char.ToUpper(s1[i]));
            Console.Write(result);
        }
    }
}
