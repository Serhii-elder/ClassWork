using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace Array
{
    class Program
    {
        static void Main(string[] args)
        {
            
            int[] arr1 = { 3, 4, 5 };
            int[] arr2 = { 5, 6, 7, 8 };

            int[] arr  = new int [arr1.Length+arr2.Length];
            for (int i = 0; i < arr.Length; i++)
            {
               
                if (i < arr1.Length)
                {
                    
                    
                    arr[i] = arr1[i];
                }
                else 
                {

                   
                    
                    arr[i] = arr2[i - 3];
                }
                
            }

            int[] tmp = arr;
           
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(tmp[i] + " ");
            }

            int duo = 0;
            int numb = 0;
            for (int i = 0; i < tmp.Length; i++)
            {
                duo = 0;
                for (int j = 0; j < arr.Length; j++)
                {
                    if(tmp[i] == arr[j])
                    {
                        duo++;
                    }
                    if(duo == 2)
                    {
                        arr[j] = arr[j + 1];
                        numb++;
                    }
                }
            }
            
            Resize(ref arr, arr.Length - numb);

            Console.WriteLine();
            for (int i = 0; i < arr.Length; i++)
            {
                Console.Write(arr[i] + " ");
            }
            Console.WriteLine();
        }
    }
}
