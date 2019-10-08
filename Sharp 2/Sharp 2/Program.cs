using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sharp_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int size = 0;
            int size1 = 0;
            int[] a = new int[5];

            for (int i = 0; i < a.Length; i++)
            {                    
                    
                    a[i] = int.Parse(Console.ReadLine());
                if (a[i] % 2 == 0) size1 += a[i];
                size += a[i];

            }
                     
            for (int j = 0; j < a.Length; j++)
           {
               Console.Write(a[j]+"\t");
           }
           Console.WriteLine();
            Console.WriteLine();
            Console.WriteLine();



            Random rnd = new Random();
            Random x = new Random();

            double t = 0;

            double [,] b = new double[3,4];

            double max = b[0, 0];
            double min = b[0, 0];

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    b[i, j] = rnd.Next(-100,100)+rnd.NextDouble();
                    if (max < b[i, j]) max = b[i, j];
                    if (min > b[i, j]) min = b[i, j];

                    if(j+1 % 2 != 0)
                    {
                        t += b[i, j];
                    }

                }             
            }

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Console.Write(b[i,j]+"\t");
                }
                Console.WriteLine();
            }
            Console.WriteLine();
            Console.WriteLine();

            Console.WriteLine(a.Max()+" max value A!");
            Console.WriteLine();
            Console.WriteLine(size+" a[i] + a[i] + a[i]");
            Console.WriteLine();
            Console.WriteLine(size1+" a[i] % 2 == 0");
            Console.WriteLine();
            Console.WriteLine(max+" max value b!");
            Console.WriteLine();
            Console.WriteLine(min+" min value b!");
            Console.WriteLine();
            Console.WriteLine(t+" suma!");

            Console.ReadKey();     
           
        }
        
    }
}
