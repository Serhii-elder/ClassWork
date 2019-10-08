using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Polimorfizm
{
    abstract class Figura
    {
        abstract public double Area();

        abstract public int Perimetr(); 
    }

    class  Square :  Figura
    {
        private int side;
        
        public Square(int side)
        {
            this.side = side;
        }
        public int Side
        {
            get { return side; }
        }

        public override double Area()
        {
            return side * side;
        }

        public override int Perimetr()
        {
            return side * 4;
        }

        public void Show()
        {
            Console.WriteLine("I am Square!");
        }
    }
    class Triangle : Figura
    {
        private int sideA;
        private int sideB;
        private int sideC;
        

        public Triangle(int sideA, int sideB,int sideC)
        {
            this.sideA = sideA;
            this.sideB = sideB;
            this.sideC = sideC;
        }
        public int SideA
        {
            get { return sideA; }
        }
        public int SideB
        {
            get { return sideB; }
        }
        public int SideC
        {
            get { return sideC; }
        }

        public override double Area()
        {
            double p = (sideA + sideB + sideC) / 2;

            double S = p * (p - sideA) * (p - sideB) * (p - sideC);

            return S/S;
        }

        public override int Perimetr()
        {
            return sideA + sideB + sideC;
        }

        public void Show()
        {
            Console.WriteLine("I am Triangle!");
        }

    }


    class Ractengle : Figura
    {
        private int sideA;
        private int sideB;


        public int SideA
        {
            get { return sideA; }
        }
        public int SideB
        {
            get { return sideB; }
        }


        public override double Area()
        {           
            return sideB / sideA;
        }

        public override int Perimetr()
        {
            return sideA * 2 + sideB * 2;
        }

        public void Show()
        {
            Console.WriteLine("I am Ractangle!");
        }
    }

    class OllFigura
    {
        private Figura[] figure;

        public OllFigura(params Figura[] figures)
        {

        }
        public void Show()
        {
         foreach (var person in people)
             {
                 person.Show();
                 Console.WriteLine(new string ('-', 30));
             }

        }
​

    }
    class Program
    {
        static void Main(string[] args)
        {
            OllFigura f = new OllFigura(new Square(4));
        }
    }
}
