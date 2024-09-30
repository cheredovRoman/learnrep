using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
    class value
    {
        private int max = 0;
        private int min = 0;
        public value()
        {
            max = 0;
            min = 0;
        }
        public int Getmax()
        {
            return this.max;
        }
        public int Getmin()
        {
            return this.min;
        }
        public void Initvalue(int MAX, int MIN)
        {
            this.max = MAX;
            this.min = MIN;
        }
        public void Inputvalue()
        {
            Console.WriteLine("\nPlease enter your MAX salary  : ");
            max = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("\nPlease enter your MIN salary  : ");
            min = Convert.ToInt32(Console.ReadLine());

        }
        public void Outputvalue()
        {
            Console.WriteLine("Your MAX salary: " + max + "\n");
            Console.WriteLine("Your MIN salary: " + min + "\n");
        }
        public void Deletevalue()
        {
            this.max = 0;
            this.min = 0;
        
        }
        public int Max
        {
            get => max;
            set => max = value;
        }
        public int Min
        {
            get => min;
            set => min = value;
        }

    }
}
