using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Snape
{
    class Figura
    {
        public  void Print()
        {
           
            

            Console.WriteLine();
            Console.WriteLine("*     **     *");
            Console.WriteLine(" *   *  *   * ");
            Console.WriteLine("  * *    * *  ");
            Console.WriteLine("   *      *   ");
            
          
        }
        public  void Print(string a)
        {
            
            Console.ForegroundColor = (ConsoleColor)Enum.Parse(typeof(ConsoleColor),a);
            

            Console.WriteLine();
            Console.WriteLine("*     **     *");
            Console.WriteLine(" *   *  *   * ");
            Console.WriteLine("  * *    * *  ");
            Console.WriteLine("   *      *   ");
            
          
        }
        public void Dispose() {

            Console.ResetColor();
        }
    }
    
    class Program
    {
        static void Main(string[] args)
        {
            string a = Console.ReadLine();
            Figura CarLogo = new Figura();
            CarLogo.Print(a);
            try
            {
                       
            }
            finally
            {
                CarLogo.Dispose();
            }
            CarLogo.Print();

            Console.ReadLine();
        }
    }
}
    
