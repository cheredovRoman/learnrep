using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
    class place
    {
        private string country = "";
        private string city = "";
        public place()
        {
            country = "";
            city = "";
        }
        public string Getcountry()
        {
            return this.country;
        }
        public string Getcity()
        {
            return this.city;
        }
        public void Initplace(string COUNTRY, string CITY)
        {
            this.country = COUNTRY;
            this.city = CITY;
        }
        public void Inputplace()
        {
            Console.WriteLine("\nPlease enter your country : ");
            country = Console.ReadLine();
            Console.WriteLine("\nPlease enter your city : ");
            city = Console.ReadLine();

        }
        public void Outputplace()
        {
            if ((country == "") && (city == ""))
            {
                Console.WriteLine("Your country: Empty\n");
                Console.WriteLine("Your city: Empty\n");
            }
            else
            {
                Console.WriteLine("Your country: " + country + "\n");
                Console.WriteLine("Your city: " + city + "\n");
            }
            Console.WriteLine("\n");

        }
        public void Deleteplace()
        {
            this.country = "";
            this.city = "";
        }
    }
}
