using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LINQProduct
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Category> cate = new List<Category>()
            {
                new Category("Electronic",1,"Electronic produdukts"),
                new Category("Health",2,"Fond tabletochki"),
                new Category("Books",3,"Books"),
                new Category("Home",4,"Homes"),
                new Category("Sport",5,"Product of sports")
            };

            List<Product> prod = new List<Product>()
            {
                new Product(1001,"AirPods",4000,new DateTime(2010,10,12),"China",1),
                new Product(1002,"Lord of Skyrim",900,new DateTime(2012,1,23),"Poland",3),
                new Product(1003,"Aspirine",0,new DateTime(2002,7,8),"USA",2),
                new Product(1004,"Bed",5600,new DateTime(2018,11,11),"France",4),
                new Product(1005,"SnowBoard",3300,new DateTime(2015,10,12),"Russia",5),
                new Product(1006,"Redmi Note 8Pro",8000,new DateTime(2019,9,9),"China",1),               
            };

            //foreach (Product it in prod)
            //{
            //    it.Show();
            //}

            var f = from p in prod where (p.Price < 7000 && p.Price > 100) select p.Name;

            var a = from p in prod where (p.Countryprod =="China" && (DateTime.Now.Year-p.Dataprod.Year)<=2) select p.Name;

            var m = from p in prod where (p.Name.Contains("A")) select new {  p.Name,p.Countryprod };

            decimal max = 0, min = 10000000; 
            for (int i = 0; i < 6; i++)
            {
                for (int j = 0; j < 6; j++)
                {
                    if(prod[i].Price > max)
                    {
                        max = prod[i].Price;
                    }
                    if (prod[i].Price < min)
                    {
                        min = prod[i].Price;
                    }
                }
            }
          
            var n = from p in prod where (p.Price==min||p.Price == max) select p.Name;
            decimal asd = 0,d = 0;
            var z = from p in prod where (p.Countryprod =="USA") select p.Price;
            foreach (var it in z)
            {
                asd += it;
                d++;
            }
            asd = asd / d;
            Console.WriteLine("USA"+ asd);
            var qwery = prod.Where(i => i.Name.Contains("ho"));



            foreach (var it in n)
            {
                Console.WriteLine(it);
            }
        }
    }
}
