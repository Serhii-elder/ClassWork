using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DZ
{
    class Program
    {
        static void Main(string[] args)
        {

            string str;
            str = Console.ReadLine();
            int size = 0;
            int i = 0;

            while( i <= str.Length||str.ToCharArray()[i] == '.')
            {               
                if (str.ToCharArray()[i] == ' ')
                {
                    size++;
                }
                i++;
            }

            Console.WriteLine($"Size ' ' = {size}");
        }
    }
}
