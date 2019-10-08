using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductSharp
{
    class Program
    {
        class Person
        {
            public string Name { get; set; }
            public int Age { get; set; }

            public override string ToString()
            {
                return "Person: " + Name + " " + Age;
            }
            static void Main(string[] args)
        {
        
            Person person = new Person { Name = "John", Age = 12 };
            Console.WriteLine(person);
        }
    
    }
}
}
