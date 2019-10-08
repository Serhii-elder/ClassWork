using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Globalization;
using System.Text.RegularExpressions;

namespace Task3_03._10
{
    class Program
    {
        static void Main(string[] args)
        {
            string pattern = @"[0-9]+";
            string path = @"C:\Users\Dovmat\source\repos\Task3 03.10\Task3 03.10\Text.txt";
            bool success = false;
            string str = "";
            try
            {
                using (StreamReader sr = new StreamReader(path, Encoding.Default))
                {
                    str = sr.ReadToEnd();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Console.WriteLine(str);

            Console.WriteLine(str);
            try
            {
                success = Regex.IsMatch(str, pattern);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            if (success)
            {
                List<int> l = new List<int>();
                MatchCollection matches = Regex.Matches(str, pattern);
                Console.WriteLine("-----");
                foreach (Match match1 in matches)
                {

                    foreach (Capture capture in match1.Captures)
                    {
                        l.Add(int.Parse(capture.Value));
                    }
                }
                foreach (var item in l)
                {
                    Console.WriteLine(item);
                }
                Console.WriteLine("-----");
            }//string pattern = @"\d";

           
            

            try
            {
                using (StreamReader sr = new StreamReader(path, Encoding.Default))
                {
                    str = sr.ReadToEnd();
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            Console.WriteLine(str);
            try
            {
                success = Regex.IsMatch(str, pattern);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            if (success)
            {
                List<int> l = new List<int>();
                MatchCollection matches = Regex.Matches(str, pattern);
                Console.WriteLine("-----");
                foreach (Match match1 in matches)
                {
                    foreach (Capture capture in match1.Captures)
                    {
                        l.Add(int.Parse(capture.Value));
                    }
                }
                foreach (var item in l)
                {
                    Console.WriteLine(item);
                }
                Console.WriteLine("-----");
            }

        }

    }
}

