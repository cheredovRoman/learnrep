using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
    class obr
    {
        private string university = "";
        private string special = "";
        public obr()
        {
            university = "";
            special = "";
        }
        public string Getuniversity()
        {
            return this.university;
        }
        public string Getspecial()
        {
            return this.special;
        }
        public void Initobr(string UNIVERSITY, string SPECIAL)
        {
            this.university = UNIVERSITY;
            this.special = SPECIAL;
        }
        public void Inputobr()
        {
            Console.WriteLine("\nPlease enter your university : ");
            university = Console.ReadLine();
            Console.WriteLine("\nPlease enter your special : ");
            special = Console.ReadLine();

        }
        public void Outputobr() 
        {
            if ((university == "") && (special == ""))
            {
                Console.WriteLine("Your university: Empty\n");
                Console.WriteLine("Your special: Empty\n");
            }
            else
            {
                Console.WriteLine("Your university: " + university + "\n");
                Console.WriteLine("Your special: " + special + "\n");
            }
            Console.WriteLine("\n");

        }
        public void deleteobr()
        {
            this.university = "";
            this.special = "";
        }
    }
}
