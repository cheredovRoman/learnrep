using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleApp2
{
    class Program
    {
        static void Main(string[] args)
        {
            bool isPass;
            int decision;

            Team[] myf1team = new Team[3];
            for (int i = 0; i < 3; i++)
                myf1team[i] = null;

            do
            {
                Console.Clear();
                isPass = false;
                decision = Function.choosingTeam(myf1team);
                if (decision != 3)
                {
                    myf1team[decision].InteractSlot();
                }
            } while (isPass == false);
        }
    }
}
