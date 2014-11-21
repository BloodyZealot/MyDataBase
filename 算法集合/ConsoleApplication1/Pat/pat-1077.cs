using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication1.Pat
{
    class pat_1077
    {
        public static void Main(string[] args)
        {
            string s1, s2;
            StringBuilder result;
            int n = int.Parse(Console.ReadLine());
            s1 = Console.ReadLine();
            s2 = Console.ReadLine();
            int l1 = s1.Length - 1, l2 = s2.Length - 1;
            for (; l1 != -1 && l2 != -1; --l1, --l2)
                if (s1[l1] != s2[l2])
                    break;
            result = new StringBuilder(s1.Substring(l1 + 1));
            n -= 2;
            for (int i = 0; i != n; ++i)
            {
                s1 = Console.ReadLine();
                while (!s1.EndsWith(result.ToString()) && result.Length != 0)
                    result.Remove(0, 1);
                if (result.Length == 0)
                {
                    Console.Write("nai");
                    return;
                }
            }
            Console.Write(result.ToString());
        }
    }
}
