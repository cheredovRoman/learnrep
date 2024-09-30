using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleApp2
{
    internal class Facility
    {
        Bureau aerodynamics;
        Bureau powertrain;
        Bureau chassis;
        Bureau durability;
        public Facility()
        {
            aerodynamics = new Bureau();
            powertrain = new Bureau();
            chassis = new Bureau();
            durability = new Bureau();
        }

        public void GetInfoBureauAerodynamics()
        {
            Console.WriteLine("Aerodynamics: ");
            Console.WriteLine("   Level: " + aerodynamics.GetLevel());
            Console.WriteLine("   Fabrication: " + aerodynamics.GetFabrication());
            Console.WriteLine("   Build Time: " + aerodynamics.GetBuildTime());
            Console.WriteLine("   Quality Control: " + aerodynamics.GetQualityControl());
            Console.WriteLine("   Duraresource Point Generationbility: " + aerodynamics.GetResourcePointGeneration() + "\n");
        }
        public void GetInfoBureauPowertrain()
        {
            Console.WriteLine("Powertrain: ");
            Console.WriteLine("   Level: " + powertrain.GetLevel());
            Console.WriteLine("   Fabrication: " + powertrain.GetFabrication());
            Console.WriteLine("   Build Time: " + powertrain.GetBuildTime());
            Console.WriteLine("   Quality Control: " + powertrain.GetQualityControl());
            Console.WriteLine("   Duraresource Point Generationbility: " + powertrain.GetResourcePointGeneration() + "\n");
        }
        public void GetInfoBureauChassis()
        {
            Console.WriteLine("Chassis: ");
            Console.WriteLine("   Level: " + chassis.GetLevel());
            Console.WriteLine("   Fabrication: " + chassis.GetFabrication());
            Console.WriteLine("   Build Time: " + chassis.GetBuildTime());
            Console.WriteLine("   Quality Control: " + chassis.GetQualityControl());
            Console.WriteLine("   Duraresource Point Generationbility: " + chassis.GetResourcePointGeneration() + "\n");
        }
        public void GetInfoBureauDurability()
        {
            Console.WriteLine("Durability: ");
            Console.WriteLine("   Level: " + durability.GetLevel());
            Console.WriteLine("   Fabrication: " + durability.GetFabrication());
            Console.WriteLine("   Build Time: " + durability.GetBuildTime());
            Console.WriteLine("   Quality Control: " + durability.GetQualityControl());
            Console.WriteLine("   Duraresource Point Generationbility: " + durability.GetResourcePointGeneration() + "\n");
        }
        public void SetFacilityBureausLevel_interface()
        {
            bool isPass, isCycled;
            int decision;

            do
            {
                isCycled = true;
                Console.Clear();

                Console.ForegroundColor = ConsoleColor.Green;
                Console.WriteLine("Bereaus:\n");
                Console.ResetColor();

                Console.Write("1) "); GetInfoBureauAerodynamics();
                Console.WriteLine("");
                Console.Write("2) "); GetInfoBureauPowertrain();
                Console.WriteLine("");
                Console.Write("3) "); GetInfoBureauChassis();
                Console.WriteLine("");
                Console.Write("4) "); GetInfoBureauDurability();

                Console.Write("\nPick Bureau you want to upgrade (0 - return)...");

                do
                {
                    isPass = false;
                    decision = Convert.ToInt32(Console.ReadLine());
                    if ((decision >= 1 && decision <= 4) || decision == 0)
                        isPass = true;
                } while (isPass == false);

                switch (decision)
                {
                    case 1:
                        if (aerodynamics.GetLevel() < 4)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("\nAerodynamics Bureau has been upgraded.");
                            Console.ResetColor();
                            aerodynamics.UpgradeBureau();
                        }
                        else Console.Write("\nAerodynamics Bureau is already at the top level.");
                        Thread.Sleep(1500);
                        break;
                    case 2:
                        if (powertrain.GetLevel() < 4)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("\nPowertrain Bureau has been upgraded.");
                            Console.ResetColor();
                            powertrain.UpgradeBureau();
                        }
                        else Console.Write("\nPowertrain Bureau is already at the top level.");
                        Thread.Sleep(1500);
                        break;
                    case 3:
                        if (chassis.GetLevel() < 4)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("\nChassis Bureau has been upgraded.");
                            Console.ResetColor();
                            chassis.UpgradeBureau();
                        }
                        else Console.Write("\nChassis Bureau is already at the top level.");
                        Thread.Sleep(1500);
                        break;
                    case 4:
                        if (durability.GetLevel() < 4)
                        {
                            Console.ForegroundColor = ConsoleColor.Green;
                            Console.Write("\nDurability Bureau has been upgraded.");
                            Console.ResetColor();
                            durability.UpgradeBureau();
                        }
                        else Console.Write("\nDurability Bureau is already at the top level.");
                        Thread.Sleep(1500);
                        break;
                    case 0:
                        isCycled = false;
                        break;
                }
            } while (isCycled == true);
        }

        public int ReturnAerodynamicsLevel()
        {
            return aerodynamics.GetLevel();
        }
        public int ReturnPowertrainLevel()
        {
            return powertrain.GetLevel();
        }
        public int ReturnChassisLevel()
        {
            return chassis.GetLevel();
        }
        public int ReturnDurabilityLevel()
        {
            return durability.GetLevel();
        }
    }
}
