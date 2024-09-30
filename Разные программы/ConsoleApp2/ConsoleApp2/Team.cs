using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Team
	{

		public Driver firstDriver = new Driver();
		public Driver secondDriver = new Driver();
		public Vehicle w11_1 = new Vehicle();
		public Vehicle w11_2 = new Vehicle();
		public Facility facility = new Facility();
		public Sponsor mainSponsor = new Sponsor();
		public Sponsor secondarySponsor = new Sponsor();

		public Team()
		{

		}
		public void InteractSlot()
		{
			int decision;
			bool isPass, isCycled;

			do
			{
				isCycled = true;
				GetTeamInfo();

				Console.WriteLine("1) Change Driver");
				Console.WriteLine("2) Change Vehicle");
				Console.WriteLine("3) Change Sponsor");
				Console.WriteLine("4) Upgrade Facilities");
				Console.WriteLine("5) Return");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if (decision >= 1 && decision <= 5)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						ChangeDriver();
						isCycled = true;
						break;
					case 2:
						ChangeVehicle();
						isCycled = true;
						break;
					case 3:
						ChangeSponsor();
						break;
					case 4:
						facility.SetFacilityBureausLevel_interface();
						break;
					case 5:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}

		public void GetTeamInfo()
		{
			Console.Clear();

			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine("F1 Team: \n");
			Console.ResetColor();

			if (firstDriver.isDriverHired())
			{
				Console.Write("1) ");
				firstDriver.GetInfo();
			}
			else
			{
				Console.ForegroundColor = ConsoleColor.Green;
				Console.Write("1) Driver");
				Console.ResetColor();
				Console.WriteLine(" not hired");
			}

			if (secondDriver.isDriverHired())
			{
				Console.Write("\n2) ");
				secondDriver.GetInfo();
			}
			else
			{
				Console.ForegroundColor = ConsoleColor.Green;
				Console.Write("\n2) Driver");
				Console.ResetColor();
				Console.WriteLine(" not hired");
			}

			Console.ForegroundColor = ConsoleColor.Green;
			Console.Write("\nVehicle 1: ");
			Console.ResetColor();
			w11_1.GetInfo();

			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine("\nVehicle 2: ");
			Console.ResetColor();
			w11_2.GetInfo();

			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine("\nMain Sponsor: ");
			Console.ResetColor();
			mainSponsor.GetInfoSponsor();

			Console.ForegroundColor = ConsoleColor.Green;
			Console.WriteLine("\nSecondary Sponsor: ");
			Console.ResetColor();
			secondarySponsor.GetInfoSponsor();

			Console.WriteLine("\nFacilities:");
			facility.GetInfoBureauAerodynamics();
			facility.GetInfoBureauPowertrain();
			facility.GetInfoBureauChassis();
			facility.GetInfoBureauDurability();
		}

		public void ChangeDriver()
		{
			int decision;
			bool isPass, isCycled;

			do
			{
				isCycled = true;
				Console.Clear();
				Console.WriteLine("1) Change First Driver");
				Console.WriteLine("2) Change Second Driver");
				Console.WriteLine("3) Return");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if (decision >= 1 && decision <= 3)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						SubChangeDriver(1);
						break;
					case 2:
						SubChangeDriver(2);
						break;
					case 3:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}

		public void SubChangeDriver(int whichDriver)
		{
			String tempString;
			int tempInt;
			double tempDouble;
			Console.Clear();

			Console.Write("Enter Driver's Name: ");
			tempString = Console.ReadLine();
			if (whichDriver == 1) firstDriver.SetName(tempString);
			else secondDriver.SetName(tempString);

			Console.Write("Enter Driver's Number: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetNumber(tempInt);
			else secondDriver.SetNumber(tempInt);

			Console.Write("Enter Driver's Overall Rating: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetOverallRating(tempInt);
			else secondDriver.SetOverallRating(tempInt);

			Console.Write("Enter Driver's Experience: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetExperience(tempInt);
			else secondDriver.SetExperience(tempInt);

			Console.Write("Enter Driver's Racecraft: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetRacecraft(tempInt);
			else secondDriver.SetRacecraft(tempInt);

			Console.Write("Enter Driver's Awareness: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetAwareness(tempInt);
			else secondDriver.SetAwareness(tempInt);

			Console.Write("Enter Driver's Pace: ");
			tempInt = Convert.ToInt32(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetPace(tempInt);
			else secondDriver.SetPace(tempInt);

			Console.Write("Enter Driver's salary: ");
			tempDouble = Convert.ToDouble(Console.ReadLine());
			if (whichDriver == 1) firstDriver.SetSalary(tempDouble);
			else secondDriver.SetSalary(tempInt);
		}

		public void ChangeVehicle()
		{
			int decision;
			bool isPass, isCycled;

			do
			{
				Console.Clear();

				isCycled = true;
				Console.WriteLine("1) Change Vehicle 1");
				Console.WriteLine("2) Change Vehicle 2");
				Console.WriteLine("3) Return\n");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if (decision >= 1 && decision <= 3)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						SubChangeVehicle(1);
						isCycled = true;
						break;
					case 2:
						SubChangeVehicle(2);
						isCycled = true;
						break;
					case 3:
						isCycled = false;
						break;
				}
			} while (isCycled == true);
		}

		public void SubChangeVehicle(int carNumber)
		{
			int decision;
			bool isPass, isCycled;
			String tempString;
			do
			{
				isCycled = true;
				Console.Clear();

				Console.WriteLine("1) Change Vehicle name");
				Console.WriteLine("2) Change Vehicle driver");
				Console.WriteLine("3) Change Vehicle components");
				Console.WriteLine("4) Change Vehicle Tyres");
				Console.WriteLine("5) Sticker Management");
				Console.WriteLine("6) Update Vehicle total component wear ratio due to facilities level");
				Console.WriteLine("7) Return\n");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if (decision >= 1 && decision <= 7)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						Console.Clear();

						Console.Write("Enter new Vehicle Name: ");
						tempString = Console.ReadLine();
						if (carNumber == 1) w11_1.SetName(tempString);
						else w11_2.SetName(tempString);
						break;
					case 2:
						do
						{
							Console.Clear();

							Console.WriteLine("Which Driver you want to assign on this Vehicle:");
							firstDriver.GetInfo();
							Console.WriteLine("");
							secondDriver.GetInfo();

							Console.WriteLine("1) Assign First Driver");
							Console.WriteLine("2) Assign Second Driver");
							Console.WriteLine("3) Return\n");

							do
							{
								isPass = false;
								decision = Convert.ToInt32(Console.ReadLine());
								if (decision >= 1 && decision <= 3)
									isPass = true;
							} while (isPass == false);

							switch (decision)
							{
								case 1:
									if (firstDriver.isDriverHired())
										if (carNumber == 1)
											w11_1.SetDriver(firstDriver);
										else w11_2.SetDriver(firstDriver);
									break;
								case 2:
									if (secondDriver.isDriverHired())
										if (carNumber == 1)
											w11_1.SetDriver(secondDriver);
										else w11_2.SetDriver(secondDriver);
									break;
								case 3:
									isCycled = false;
									break;
							}
						} while (isCycled);
						isCycled = true;
						break;
					case 3:
						if (carNumber == 1) w11_1.SetComponents_interface();
						else w11_2.SetComponents_interface();
						isCycled = true;
						break;
					case 4:
						if (carNumber == 1) w11_1.SetTyres_interface();
						else w11_2.SetTyres_interface();
						break;
					case 5:
						do
						{
							isCycled = true;
							Console.Clear();
							Console.ForegroundColor = ConsoleColor.Green;
							Console.WriteLine("Stickers on the Vehicle:");
							Console.ResetColor();
							if (carNumber == 1)
								w11_1.GetSponsorStickers();
							else w11_2.GetSponsorStickers();

							Console.WriteLine("\n1) Add Sticker on the Vehicle");
							Console.WriteLine("2) Delete Sticker on the Vehicle");
							Console.WriteLine("3) Return\n");

							do
							{
								isPass = false;
								decision = Convert.ToInt32(Console.ReadLine());
								if (decision >= 1 && decision <= 3)
									isPass = true;
							} while (isPass == false);

							switch (decision)
							{
								case 1:
									Console.Clear();

									Console.Write("Enter name of the new sticker: ");
									Console.ReadLine();
									tempString = Console.ReadLine();
									if (carNumber == 1)
										w11_1.AddSponsorSticker(tempString);
									else w11_2.AddSponsorSticker(tempString);

									break;
								case 2:
									Console.Clear();

									Console.Write("Enter name of the sticker to delete: ");
									Console.ReadLine();
									tempString = Console.ReadLine();

									if (carNumber == 1)
										if (w11_1.DeleteSponsorSticker(tempString))
											Console.WriteLine("Sticker has been deleted");

										else Console.WriteLine("No sticker to delete");

									else if (w11_2.DeleteSponsorSticker(tempString))
										Console.WriteLine("Sticker has been deleted");

									else Console.WriteLine("No sticker to delete");

									break;
								case 3:
									isCycled = false;
									break;
							}
						} while (isCycled);
						isCycled = true;
						break;
					case 6:
						if (carNumber == 1) w11_1.SetTotalComponentWearRatio(facility.ReturnAerodynamicsLevel(), facility.ReturnPowertrainLevel(), facility.ReturnChassisLevel(), facility.ReturnDurabilityLevel());
						else w11_2.SetTotalComponentWearRatio(facility.ReturnAerodynamicsLevel(), facility.ReturnPowertrainLevel(), facility.ReturnChassisLevel(), facility.ReturnDurabilityLevel());
						break;
					case 7:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}

		public void ChangeSponsor()
		{
			int decision;
			bool isPass, isCycled;

			do
			{
				Console.Clear();
				isCycled = true;

				Console.WriteLine("1) Change Main Sponsor");
				Console.WriteLine("2) Change Secondary Sponsor");
				Console.WriteLine("3) Return");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if (decision >= 1 && decision <= 3)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						SubchangeSposnor(1);
						break;
					case 2:
						SubchangeSposnor(2);
						break;
					case 3:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}

		public void SubchangeSposnor(int whichSponsor)
		{
			int decision;
			bool isPass, isCycled;
			String tempString;
			double tempDouble;

			Console.Clear();

			Console.Write("Enter name of the main sponsor: ");
			tempString = Console.ReadLine();
			if (whichSponsor == 1) mainSponsor.SetName(tempString);
			else secondarySponsor.SetName(tempString);

			Console.WriteLine("");
			if (whichSponsor == 1) mainSponsor.SetTargetRace_interface();
			else secondarySponsor.SetTargetRace_interface();

			Console.WriteLine("\n");
			if (whichSponsor == 1) mainSponsor.SetTargetSeason_interface();
			else secondarySponsor.SetTargetSeason_interface();

			Console.WriteLine("\n");
			Console.Write("Enter sponsor's payment per race: ");
			tempDouble = Convert.ToDouble(Console.ReadLine());
			if (whichSponsor == 1) mainSponsor.SetPaymentPerRace(tempDouble);
			else secondarySponsor.SetPaymentPerRace(tempDouble);

			Console.Write("\nEnter sponsor's target bonus ratio: ");
			tempDouble = Convert.ToDouble(Console.ReadLine());
			if (whichSponsor == 1) mainSponsor.SetTargetBonusRatio(tempDouble);
			else secondarySponsor.SetTargetBonusRatio(tempDouble);
		}
	}
}
