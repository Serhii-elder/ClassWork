using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Store
{
    class Provider
    {
        // private fields
        private string name;
        private string country;
        private short raiting;
        private bool isPayVAT;

        // public properties for getting and setting (get, set)
        public string Name
        {
            get { return name; }
            set { name = value; }
        }
        public string Country
        {
            get { return country; }
            set { country = value; }
        }
        public short Raiting
        {
            get { return raiting; }
            set { raiting = value; }
        }
        public bool IsPayVAT
        {
            get { return isPayVAT; }
            set { isPayVAT = value; }
        }

        // Constructor        
        public Provider(string name, string country)
        {
            Console.WriteLine(Name);
            Name = "jhgjuh";

            this.name = name;
            this.country = country;
            raiting = (short)new Random().Next(6);  // randomize number from 0 to 5
            isPayVAT = (raiting > 2);   // if raiting more than 2, provider paying VAT
        }
        public void Show()
        {
            Console.WriteLine($"Name: {name}\n" +
                $"Country: {country}\n" +
                $"Raiting: {(raiting > 0 ? new string('*', raiting) : "No raiting")}\n" + // if there`s raiting, create string with ctor
                $"{(isPayVAT ? "Pay VAT" : "Not pay VAT")}\n");
        }
    }
}
