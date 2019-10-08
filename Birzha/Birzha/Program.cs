using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Birzha
{
    public delegate void DelegateSell();

    public delegate void DelegateProd();

    class Saller
    {
        public string Name { get; set;}

        

        public void Sell()
        {
            Console.WriteLine("I prodavay:");
        }

    }

    class Pokupec
    {
        public string Name { get; set; }       

        public void Pocup() {
            Console.WriteLine(Name + " pocupay:");           
        }
    }

    class Birzha
    {
        private DelegateSell delegateSell;

        public event DelegateSell SellEvent
        {
            add { delegateSell += value; }
            remove { delegateSell -= value; }
        }

        public event DelegateProd PocupEvent;
    

        private const int maxPrice =10;
        private const int mixPrice =0;
        private int price;

        public int Price {
            get { return price; }
            set { price = value; }
        }
        public void Rand()
        {
            price = 5;

            Random rnd = new Random();
            price += rnd.Next(-3, 3);
            if(price > 10)
            {
                price = 10;
            }else if (price < 0)
            {
                price = 0;
            }

            if (Price >= 7)
            {
                delegateSell?.Invoke();

            }
            else if (Price <= 3)
            {
                PocupEvent?.Invoke();
            }
        }

        public void show()
        {
            for (int i = 1; i < 11; i++)
            {
                if (i == price)
                {
                    Console.WriteLine("*");
                }
                else 
                {Console.WriteLine(i);}
            }
        }



    }

    class Program
    {
        static void Main(string[] args)
        {

            Saller saller = new Saller() {Name = "saller 1" };

            Pokupec pokupec = new Pokupec() { Name = "pocupec 1"};
            Pokupec pokupec2 = new Pokupec() { Name = "Diatel" };

            Birzha birzha = new Birzha();

            birzha.PocupEvent += pokupec.Pocup;
            birzha.SellEvent += saller.Sell;
            birzha.PocupEvent += pokupec2.Pocup;

            while (true)
            {
                birzha.Rand();              
                birzha.show();
                Console.WriteLine();
                Console.ReadKey();
                Console.WriteLine();
            }
        }
    }
}
