using System;
using System.Collections.Generic;
using System.Text;

namespace lab6
{
   public class setacc
    {
        //Account
        private string name = ""; //Имя
        private string surname = ""; //Фамилия
        private string email = ""; //Почта
        private string password = ""; //Пароль
        //obr
        public string university = "";//Университет
        public string special = "";//Специальность
        //place
        public string country = "";//Страна
        public string city = "";//Город
        //value
        public int max = 0;//Максимальная зарплата
        public int min = 0;//Минимальная зарплата

        public setacc() {
            name = ""; //Имя
            surname = ""; //Фамилия
            email = ""; //Почта
            password = ""; //Пароль
            university = "";//Университет
            special = "";//Специальность
            country = "";//Страна
            city = "";//Город
            max = 0;//Максимальная зарплата
            min = 0;//Минимальная зарплата
        }
        public string Getname()
        {
            return this.name;
        }
        public string Getsurname()
        {
            return this.surname;        
        }
        public string Getemail()
        {
            return this.email;
        }
        public string Getpassword()
        {
            return this.password;
        }
        public void InitAccount(string NAME, string SURNAME, string EMAIL, string PASSWORD) //Инициализация аккаунта
        {
            this.name = NAME;
            this.surname = SURNAME;
            this.email = EMAIL;
            this.password = PASSWORD;
        }
        public void InputAccount() //Изменение данных о аккаунте
        {
            Console.WriteLine("\nPlease enter a name: ");
            name = Console.ReadLine();
            Console.WriteLine("\nPlease enter a surname: ");
            surname = Console.ReadLine();
            Console.WriteLine("\nPlease enter a email: ");
            email = Console.ReadLine();
            Console.WriteLine("\nPlease enter a password: ");
            password = Console.ReadLine();
        }
        public void OutputAccount()//Вывод данных о аккаунте
        {
            Console.WriteLine("\t\t\tACCOUNT\n");
            if ((name == "") && (surname == "") && (email == "") && (password == ""))
            {
                Console.WriteLine("\nName: empty");
                Console.WriteLine("\nSurname: empty");
                Console.WriteLine("\nEmail: empty");
                Console.WriteLine("\nPassword: empty");
            }
            else
            {
                Console.WriteLine("Name: " + name + "\n");
                Console.WriteLine("Surname: " + surname + "\n");
                Console.WriteLine("Email: " + email + "\n");
                Console.WriteLine("Password: " + password + "\n");
            }
            if ((university == "") && (special == ""))
            {
                Console.WriteLine("\nuniversity: empty");
                Console.WriteLine("\nspecial: empty");
            }
            else {
                Console.WriteLine("\nuniversity: "+ university+"\n");
                Console.WriteLine("\nspecial: "+ special+"\n");
            }
            if ((country == "") && (city == ""))
            {
                Console.WriteLine("\ncountry: empty");
                Console.WriteLine("\ncity: empty");
            }
            else
            {
                Console.WriteLine("\nucountry: " + country + "\n");
                Console.WriteLine("\ncity: " + city + "\n");
            }
            if (max == 0)
                Console.WriteLine("max: Empty\n");
            else
                Console.WriteLine("max:"+max+ "\n");
            if (min == 0)
                Console.WriteLine("min: \n");
            else
                Console.WriteLine("min:" + min + "\n");


        }
        public void DeleteAccount() //Удаление аккаунта
        {
            this.name = "";
            this.surname = "";
            this.email = "";
            this.password = "";
        
        }


    }
}
