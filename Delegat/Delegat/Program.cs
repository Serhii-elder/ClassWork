using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegat
{
   

    public delegate double MyDelegate(double a, double b);
    public delegate double TriDelegate(int m);

    class Program
    {
        static void Main(string[] args)
        {
            double o = 0, p = 0 ,sum = 0;
            int i = 0;
            int c = 0;
            double summ = 0;

            Operatoin op = new Operatoin();

            MyDelegate[] opera = new MyDelegate[4];

            opera[0] = op.Add;
            opera[1] = op.Min;
            opera[2] = op.Mult;
            opera[3] = op.Div;

            o = double.Parse(Console.ReadLine());
            p = double.Parse(Console.ReadLine());
            Console.WriteLine("1 : +\t2 : -\t3 : *\t4 : /");
            i = int.Parse(Console.ReadLine());


            sum = opera[i - 1](a: o, b: p);
            Console.WriteLine(sum);

            TriDelegate[] triopera = new TriDelegate[3];

            TriOpera triop = new TriOpera();

            triopera[0] = triop.Sin;
            triopera[1] = triop.Cos;
            triopera[2] = triop.Tg;

            c = int.Parse(Console.ReadLine());

            i = int.Parse(Console.ReadLine());

            summ = triopera[i - 1](m: c);

            Console.WriteLine(summ);
        }
    }

    class Operatoin
    {
        public double Add(double x, double y)
        {
            return x + y;
        }
        public double Min(double x, double y)
        {
            return x - y;
        }
        public double Mult(double x, double y)
        {
            return x * y;
        }
        public double Div(double x, double y)
        {
            if (y == 0)
                throw new DivideByZeroException();

            return x / y;
        }
    }

    class TriOpera
    {

        public double Sin (int a)
        {
            return  Math.Sin(a);

        }

        public double Cos(int a)
        {
            return Math.Cos(a);
        }

        public double Tg (int a)
        {
            return  Math.Tan(a);
        }

    }
        
}
