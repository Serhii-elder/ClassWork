using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductSharp
{
    partial class Store
    {
        public int size = 0;
        private Product[] products;

        public Store() {

            products = new Product[20];
            for (int i = 0; i < 10; i++)
            {products[i] = new Product();
                size++;
            }
        }

        public int CountOfProducts()
        {
            return products.Length;
        }
        public int CountOfProductsType(ProductType type){
            int count = 0;
            for (int i = 0; i < products.Length; i++)
            {
                if(products[i].Info.type == type)
                {
                    count++;
                }
            }
            return count;
        }
        public decimal TotalPrice()
        {
            decimal count = 0;
            for (int i = 0; i < products.Length; i++)
            {
                count += products[i].Info.price;
            }
            return count;
        }

        public decimal AvgPrice()
        {
            decimal avg = 0;
            
            avg = TotalPrice() / products.Length;

            return avg;
        }

    }
}
