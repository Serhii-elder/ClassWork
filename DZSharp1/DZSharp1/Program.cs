using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace DZSharp1
{
    class Program
    {
        static void Main(string[] args)
        {

            int[] a = { 1, 2, 3, 4, 5 };
            int[] b = { 8, 2, 3, 4, 5 };

            var sb = new System.Text.StringBuilder(a.Length + b.Length);
            foreach (var x in a)
            {
                sb.Append(string.Format("{0} ", x));
            }

            foreach (var x in b)
            {
                sb.Append(string.Format("{0} ", x));
            }

            Console.WriteLine(sb);

            Console.WriteLine();



            string str = Console.ReadLine();

          if(str.ToCharArray().Reverse() == str.ToArray())
            {
                Console.WriteLine("yes");
            }


            Console.WriteLine(str.ToCharArray().Reverse().ToArray());
            Console.WriteLine(str.ToCharArray().ToArray());











        }
    }
}
