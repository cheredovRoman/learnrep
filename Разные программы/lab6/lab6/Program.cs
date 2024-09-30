using System;

namespace lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.Write("10) Для полей добавить свойства и продемонстрировать работу с ними\n");
            Console.Write("На примере класса value\n");
            value val = new value();
            val.Max = 5;
            val.Min = 2;
            Console.WriteLine("value: " + val.Max + " " + val.Min);
            Console.Write("11) Cоздать массив объектов и продемонстрировать работу с ним\n");
            Console.Write("На примере класса Образование\n");
            obr[] M = new obr[2];
            for (int j = 0; j < 2; j++)
                M[j] = new obr();
            M[0].Initobr("ALTGTU", "PI");
            M[1].Initobr(" Leps", "London");
            Console.Write("Output all:\n");
            for (int i = 0; i < 2; i++)
                M[i].Outputobr();
            Console.Write("12) В отдельной ветке проекта заменить класс (class) \nна структуру(struct). Продемонстрировать различие \nмежду присваиванием объектов класса и структуры\n");
            Console.Write("==================================================================\n");
            //set
            setacc User = new setacc();
            obr obraz = new obr();
            place pl = new place();
            value money = new value();
            // init
            User.InitAccount("Sergey", "Ivanov", "Ivanov@gmail.com", "123123");
            obraz.Initobr("Altgtu","PI");
            User.university=obraz.Getuniversity();
            User.special = obraz.Getspecial();
            pl.Initplace("Russia","Barnaul");
            User.country = pl.Getcountry();
            User.city = pl.Getcity();
            money.Initvalue(100000,2000);
            User.max = money.Getmax();
            User.min = money.Getmin();
            //output
            Console.WriteLine("output:");
            User.OutputAccount();
            //delete
            Console.WriteLine("\nDelete: ");
            User.DeleteAccount();
            obraz.deleteobr();
            pl.Deleteplace();
            money.Deletevalue();
            User.OutputAccount();
            //input
            Console.WriteLine("Input: ");
            User.InputAccount();
            obraz.Inputobr();
            pl.Inputplace();
            money.Inputvalue();
            Console.WriteLine("Output NEW: ");
            User.OutputAccount();
        }
    }
}
