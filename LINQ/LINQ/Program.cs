using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQ
{
    class Program
    {
        static void Main(string[] args)
        {

            string[] str = { "Blue", "Pink", "Black", "Dark", "Pink" };
            string[] str1 = { "blue", "Pink", "Black", "Blue", "pink" };
            IEnumerable<string> res;
            res = str.Concat(str1);

            IEnumerable<string> query = from i in res
                                        where i == i.Remove(0, 1).ToUpper()
                                        orderby i
                                        select i;


           // var result = res.Where(i => i == i.Remove(0, 1).ToUpper()).OrderByDescending(i => i);

            Console.WriteLine("Even elements descending:");
            foreach (string item in query)
            {
                Console.Write($"{item}\t");
            }
            Console.WriteLine();

        }
    }
}
