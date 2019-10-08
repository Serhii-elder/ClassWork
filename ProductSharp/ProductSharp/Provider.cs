using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProductSharp
{
    class Provider
    {
        private string name;
        private string country;
        private short raiting;
        private bool isPayVAT;

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


        public void Show()
        {
            char r = '*';
            string rat = new String(r,raiting);           
            Console.WriteLine($"\tName: {name}\n\t" +
                $"Countri: {country}\n\t" +
                $"{((raiting == 0) ? "Rating: 0" : $"Rating: {rat}")}\n\t" +
                $"IsPayVAT: {((isPayVAT == true) ? "Yes" : "No")}\n");
        }

        public void SetInfo(string name,string country)
        {
            this.name = name;
            this.country = country;
            Random rnd = new Random();
            raiting = (short)rnd.Next(0,6);
            isPayVAT = (raiting > 2);
        }
    }
}
