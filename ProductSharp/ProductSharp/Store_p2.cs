using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductSharp
{
    partial class Store
    {

        public override string ToString()
        {
            string str = "";
            for (int i = 0; i < products.Length; i++)
            {
                str += products[i].Info.name + products[i].Info.price + products[i].Info.type;
            }

            return str;
        }

        public void AddProduct()
        {

            products[size] = new Product();
            size++;
           
        }

        public void GetProd(int key)
        {
            for (int i = 0; i < products.Length; i++)
            {
                if(products[i].Info.key == key)
                {
                    products[i].Show();
                }
            }
        }

        public void DeleteProduct(int key)
        {
            Product[] prod = new Product[size - 1];

            for (int i = 0; i < products.Length; i++)
            {
                
                if (products[i].Info.key != key)
                {
                    prod[i] = products[i];
                }
            }
        }






    }
}
