using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SquareRectangle
{
    class Square
    {
        public int A { get; set; }

        public Square()
        {
            A = 0;
        }

        public Square(int a)
        {
            A = a;
        }
        public override string ToString()
        {
            return $"Side: a: {A}";
        }
        public override bool Equals(object obj)
        {
            Square side = (Square)obj;
            return A == side?.A;
        }

        public override int GetHashCode()
        {
            var hashCode = 1861411795;
            hashCode = hashCode * -1521134295 + A.GetHashCode();
            return hashCode;
        }

        public static Square operator ++(Square a)
        {
            a.A++;
            return a;
        }
        public static Square operator --(Square a)
        {
            a.A--;
            return a;
        }

        public static Square operator +(Square p1, Square p2)
        {
            Square p3 = new Square
            {
                A = p1.A + p2.A,
            };
            return p3;
        }

        public static Square operator -(Square p1, Square p2)
        {
            Square p3 = new Square
            {
                A = p1.A - p2.A,
            };
            return p3;
        }

        public static Square operator *(Square p1, Square p2)
        {
            Square p3 = new Square
            {
                A = p1.A * p2.A,
            };
            return p3;
        }


        public static Square operator /(Square p1, Square p2)
        {
            Square p3 = new Square
            {
                A = p1.A / p2.A,

            };
            return p3;
        }

        public static bool operator ==(Square p1, Square p2)
        {
            return p1.Equals(p2);
        }
        public static bool operator !=(Square p1, Square p2)
        {
            return !(p1 == p2);
        }
        public static bool operator true(Square p)
        {
            return p.A != 0;
        }
        public static bool operator false(Square p)
        {
            return p.A == 0;
        }

        public static explicit operator Square(Ractangle p)
        {
            Square p2 = new Square
            {
                A = p.A
            };

            return p2;
        }
    }


    class Ractangle
    {

        public int A { get; set; }
        public int B { get; set; }
        public Ractangle()
        {
            A = 0;
            B = 0;
        }
        public Ractangle(int a, int b)
        {
            A = a;
            B = b;
        }
        public override string ToString()
        {
            return $"Side: a: {A}, b: {B}";
        }

    }
}
