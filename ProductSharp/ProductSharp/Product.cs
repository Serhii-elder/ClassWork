using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductSharp
{
    enum ProductType : byte
    {
        Electronics = 1,
        Food,
        Medical,
        Clothes,
        Sport
    }
    struct ProductInfo{

        public string name;
        public decimal price;
        public ProductType type;
        public readonly DateTime data;
        public readonly int key;

        public ProductInfo(string name, decimal price, ProductType type, int key)
        {
            this.key = key;
            data = DateTime.Now;
            this.name = name;
            this.price = price;
            this.type = type;
        }
    }
    class Product
    {
        private Provider r;
        private ProductInfo info;
        private static int count;
        static Product()
        { ++count; }

        public Product()
        {
            GetData( out decimal price, out string name, out ProductType type);
            info = new ProductInfo( name, price, type, count + 1000);
            r = new Provider();
            r.SetInfo("Zhako", "Ukraine");
            count++;
        }

        public int Count
        {get { return count; } }

        public ProductInfo Info
        { get{ return info; } }

        public void GetData(out decimal price,out string name,out ProductType type)
        {
            //price = decimal.Parse(Console.ReadLine());
            Console.WriteLine("Price: ");
            while (!decimal.TryParse(Console.ReadLine(), out price))
            {
                Console.WriteLine("Incorect input !");
            }
            Console.WriteLine("Name: ");
            name = Console.ReadLine();   
            
            foreach (var item in Enum.GetNames(typeof(ProductType)))
            {
                Console.WriteLine(item);
            }

            Console.WriteLine("Type: ");
            while (!ProductType.TryParse(Console.ReadLine(), out type))
            {
                Console.WriteLine("Incorect input !");
            }
        }  

        public void Show()
        {
          
            Console.WriteLine($"Name: {info.name}\n" +
                $"Price: {info.price}\n" +
                $"Type: {info.type}\n" +
                $"Key: {info.key}");

                r.Show();
        }
    }
}
