using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace _03._10
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"C:\Users\Dovmat\source\repos\03.10\03.10\Text.txt";
            string path1 = @"C:\Users\Dovmat\source\repos\03.10\03.10\Necensuri.txt";
            string path2 = @"C:\Users\Dovmat\source\repos\03.10\03.10\Text1.txt";
            string Task2 = @"C:\Users\Dovmat\source\repos\03.10\03.10\Task2.txt";
            string[] arrS;
            string[] arrA;
                    
            using (StreamReader sr = new StreamReader(path))
            {
                // sr.ReadToEnd().ToString();
                arrS = sr.ReadToEnd().ToString().Split(new char[] { '-', ' ', ',', '.','?' }, StringSplitOptions.RemoveEmptyEntries);
            }

            using (StreamReader sr = new StreamReader(path1))
            {          
                    arrA = sr.ReadToEnd().ToString().Split(new char[] {' '}, StringSplitOptions.RemoveEmptyEntries);
            }

            char[] ch;
            
            try
            {
                using (StreamWriter sw = new StreamWriter(Task2, false, System.Text.Encoding.Default))
                {
                        for(int i = 0; i < arrS.Length; i++)
                       {
                           char st = arrS[i][0];
                           arrS[i]= arrS[i].Remove(0, 1).Insert(0, st.ToString().ToUpper())+".";
                       }
                    for (int i = 0; i+1< arrS.Length; i++)
                    {
                       
                        sw.WriteLine(arrS[i] );
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

            for (int i = 0; i < arrS.Length; i++)
            {
                for (int j = 0; j < arrA.Length; j++)
                {
                    if (arrS[i] == arrA[j])            
                    {
                        arrS[i] = (new string('*',arrS[i].Length));
                    }

                }
                Console.Write(arrS[i]+" ");
            }  
            
            try
            {
                using (StreamWriter sw = new StreamWriter(path2, false, System.Text.Encoding.Default))
                {                                                          
                    sw.WriteLine(string.Join(" ", arrS));                   
                }             
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }            
            Console.WriteLine();
        }
    }
}
