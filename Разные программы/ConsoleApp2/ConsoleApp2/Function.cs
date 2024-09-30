using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    internal class Function
    {
        public static int choosingTeam(Team[] myf1team)
        {
            bool isPass;
            int decision;
            int i;

            for (i = 0; i < 3; i++)
            {
                Console.WriteLine("\n" + (i + 1) + ") ");
                if (myf1team[i] != null)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("\nDrivers:");
                    Console.ResetColor();
                    Console.WriteLine("1) " + myf1team[i].firstDriver.GetName());
                    Console.WriteLine("2) " + myf1team[i].secondDriver.GetName());

                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.WriteLine("\nVehicles:");
                    Console.ResetColor();
                    Console.Write("1) "); myf1team[i].w11_1.GetInfoName();
                    Console.Write("2) "); myf1team[i].w11_2.GetInfoName();
                }
                else
                {
                    Console.WriteLine("Empty Slot\n");
                }
            }

            Console.Write("Enter slot you want to modify. (4 - clear 1 slot, 5 - clear 2 slot, 6 - clear - 3 slot)... ");

            do
            {
                isPass = false;
                decision = Convert.ToInt32(Console.ReadLine());
                if (decision >= 1 && decision <= 6)
                    isPass = true;
            } while (isPass == false);

            switch (decision)
            {
                case 1:
                    if (myf1team[0] == null)
                    {
                        myf1team[0] = new Team();
                    }
                    return 0;
                case 2:
                    if (myf1team[1] == null)
                    {
                        myf1team[1] = new Team();
                    }
                    return 1;
                case 3:
                    if (myf1team[2] == null)
                    {
                        myf1team[2] = new Team();
                    }
                    return 2;
                case 4:
                    if (myf1team[0] != null)
                    {
                        myf1team[0] = null;
                    }
                    return 3;
                case 5:
                    if (myf1team[1] != null)
                    {
                        myf1team[1] = null;
                    }
                    return 3;
                case 6:
                    if (myf1team[2] != null)
                    {
                        myf1team[2] = null;
                    }
                    return 3;
            }
            return 0;
        }
    }
}
