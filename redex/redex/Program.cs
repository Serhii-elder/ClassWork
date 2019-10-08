using System;
using System.Globalization;
using System.Text.RegularExpressions;

namespace redex
{
    class Program
    {
        static void Main(string[] args)
        {
            string pattern = @"(([1][9])|([2][0])){2}[0-9][0-9]";
           // string pattern = @"^[A-Z]{3}$";
           //string pattern = @"^[0-9]{4}$";
            
            var regex = new Regex(pattern);
            var array = new[] { "WBW", "2000", "test123test", "123test", "test123" };
            
            foreach (string element in array)
            {
                Console.WriteLine(
                    regex.IsMatch(element)
                        ? $"String \"{element}\" matched \"{pattern}\""
                        : $"String \"{element}\" NOT matched \"{pattern}\"");
                Console.WriteLine(new string('-', 50));
            }
            
          
        }
    }

}
