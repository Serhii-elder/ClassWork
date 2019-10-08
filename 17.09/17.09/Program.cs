using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _17._09
{

    //class RangOfArray
    //{
    //    private int[] array;
    //    private int arraydown;
    //    private int arrayup;
    //    private int size;
    //    public RangOfArray()
    //    {
    //        arraydown = 0;
    //        arrayup = 10;
    //        size = 10;
    //        array = new int[size];
    //    }
    //    public RangOfArray(int index)
    //    {
    //        arraydown = 0;
    //        arrayup = index;
    //        size = index;
    //        array = new int[size];
    //    }
    //    public RangOfArray(int indexup, int indexdown)
    //    {
    //        arraydown = indexdown;
    //        arrayup = indexup;
    //        size = 0;

    //        if (indexdown < 0)
    //        {
    //            indexdown *= -1;
    //        }
    //        if (indexup < 0)
    //        {
    //            indexup *= -1;
    //        }

    //        size = indexdown + indexup;

    //        array = new int[size];
    //    }
    //    public int this[int index]
    //    {
    //        get
    //        {
    //            if (index < arraydown || index > arrayup)
    //            {
    //                Console.WriteLine("Not exist index!");
    //            }
    //            return array[index - arraydown];
                
    //        }
    //        set
    //        {
    //            if (index < arraydown||index>arrayup)
    //            {
    //                Console.WriteLine("Not exist index!");
    //            }
    //            array[index - arraydown] = value;
    //        }
    //    }
    //}  

        class User
        {
        private string name;
        private int id;
        private int age;
        private string login;
        private string password;

        public override string ToString()
        {
            return "Person: " + name + " " + age + " "+ id + " " + login + " " + password;
        }
        }

        class UserList
        {
        private static int size = 0;

        User[] user = new User[size];

        public void AddUser(User user)
        {
            
        }

        }
        class Program
        {
             static void Main(string[] args)
             {
                //RangOfArray a = new RangOfArray(10,-5);

                //int r = 5;
                //a[r] = 10;

                //Console.WriteLine(a[r]);
             }
        }
}
