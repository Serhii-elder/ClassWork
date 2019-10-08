using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQProduct
{
    class Product
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public decimal Price { get; set; }
        public DateTime Dataprod { get; set; }
        public string Countryprod { get; set; }
        public int Categoryid { get; set; }

        public Product(int id,string name, decimal price ,DateTime dataprod,string countryprod,int categoryid)
        {
            Id = id;
            Name = name;
            Price = price;
            Dataprod = dataprod;
            Countryprod = countryprod;
            Categoryid = categoryid;           
        }

        public void Show()
        {
            
            Console.WriteLine();
            Console.WriteLine($"Id:\t\t\t{Id}");
            Console.WriteLine($"Name:\t\t\t{Name}");
            Console.WriteLine($"Price:\t\t\t{Price}");
            Console.WriteLine($"Data of product:\t{Dataprod.ToShortDateString()}");
            Console.WriteLine($"Countri of product:\t{Countryprod}");
            Console.WriteLine($"Category id:\t\t{Categoryid}");
            Console.WriteLine();
        }
    }
    class Category
    {
     
        string Name { get; set; }
        int Id { get; set; }
        string Description { get; set; }
        public Category(string name,int id,string description)
        {
            Name = name;
            Id = id;
            Description = description;
        }
    }
}
