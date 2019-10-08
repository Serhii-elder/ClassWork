using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _26._09
{
    //static class class1
    //{

    //   static public void NumberOfWords(this string str)
    //    {   
    //        string[] arr = str.Split(new char[] { '-', ' ', ',', '.' }, StringSplitOptions.RemoveEmptyEntries);
    //        Console.WriteLine(arr.Length);
    //    }

    //}
    class Point<T>  where T : struct
    {
        public T X { get; set; }
        public T Y { get; set; }

        public Point()
        {          
            X = default(T);
            Y = default(T);
        }
        
        public Point(T x, T y)
        {
            this.X = x;
            Y = y;
        }

        public void SetX(T newX)
        {
            X = newX;
        }
        
        public override string ToString()
        {
            return $"x: {X}, y: {Y}";
        }
       
    }

    class Line
    {
        Point<int> point1;
        Point<int> point2;

        public Line(Point<int> point1,Point<int> point2) {
            this.point1 = point1;
            this.point2 = point2;
        }
        public Line(int coor1Y,int coor2Y,int coor1X,int coor2X)
        {
            point1 = new Point<int>(coor1X, coor1Y);
            point2 = new Point<int>(coor2X, coor2Y);
        }

        public override string ToString()
        {
            return point1.ToString() + point2.ToString();
        }
    }
        class Program
    {
        static void Main(string[] args)
        {
            //string st = Console.ReadLine();
            //st.NumberOfWords();

            Line line = new Line(1, 2, 3, 4);

            Console.WriteLine(line.ToString());


        }
    }
}
