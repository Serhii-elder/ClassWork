using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ClassesSharp
{



    class PC
    {
        public string Processor;
        public string Memory;

        public void show()
        {
            Console.WriteLine($"Processor: {Processor}");
            Console.WriteLine($"Memory: {Memory}");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            PC pc = new PC();
           
            pc.show();
            pc.Memory = "Tanbash";
            pc.Processor = "Intel Xeon 775";
            pc.show();
        }
    }
}
