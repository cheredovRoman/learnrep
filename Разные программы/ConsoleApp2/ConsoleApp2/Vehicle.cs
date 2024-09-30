using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace ConsoleApp2
{
	internal class Vehicle
	{
		int sponsorStickerQuantity;

		Driver driver;

		string vehicleName;

		string[] sponsorStickers;

		Tyres tyreSet;

		public class SeasonComponents
		{
			public double totalComponentWearRatio = 3;
			public class PowerUnitSet
			{
				public Component engine1 = new Component(ComponentID.Engine);
				public Component engine2 = new Component(ComponentID.Engine);
				public Component engine3 = new Component(ComponentID.Engine);

				public Component mguKinetic1 = new Component(ComponentID.MguKinetic);
				public Component mguKinetic2 = new Component(ComponentID.MguKinetic);
				public Component mguKinetic3 = new Component(ComponentID.MguKinetic);

				public Component mguHeat1 = new Component(ComponentID.MguHeat);
				public Component mguHeat2 = new Component(ComponentID.MguHeat);
				public Component mguHeat3 = new Component(ComponentID.MguHeat);

				public Component turboCharger1 = new Component(ComponentID.TurboCharger);
				public Component turboCharger2 = new Component(ComponentID.TurboCharger);
				public Component turboCharger3 = new Component(ComponentID.TurboCharger);

				public Component energyStore1 = new Component(ComponentID.EnergyStore);
				public Component energyStore2 = new Component(ComponentID.EnergyStore);

				public Component controlElectronics1 = new Component(ComponentID.ControlElectronics);
				public Component controlElectronics2 = new Component(ComponentID.ControlElectronics);

				public InstalledComponent internalCombastionEngine = InstalledComponent.NOT_FITTED;
				public InstalledComponent mguKinetic = InstalledComponent.NOT_FITTED;
				public InstalledComponent mguHeat = InstalledComponent.NOT_FITTED;
				public InstalledComponent energyStore = InstalledComponent.NOT_FITTED;
				public InstalledComponent turboCharger = InstalledComponent.NOT_FITTED;
				public InstalledComponent controlElectronics = InstalledComponent.NOT_FITTED;
			}
			public PowerUnitSet powerUnitSet = new PowerUnitSet();
			public class Gearbox
			{
				public Component practiceGearbox1 = new Component(ComponentID.Gearbox);
				public Component practiceGearbox2 = new Component(ComponentID.Gearbox);

				public Component eventGearbox1 = new Component(ComponentID.Gearbox);
				public Component eventGearbox2 = new Component(ComponentID.Gearbox);

				public InstalledComponent practiceGearbox = InstalledComponent.NOT_FITTED;
				public InstalledComponent eventGearbox = InstalledComponent.NOT_FITTED;
			}
			public Gearbox gearboxSet = new Gearbox();
		}
		private SeasonComponents seasonComponents = new SeasonComponents();

		public Vehicle()
		{
			vehicleName = "NoName";
			sponsorStickerQuantity = 0;

			tyreSet = new Tyres();
			driver = new Driver();
			sponsorStickers = Array.Empty<string>();
		}

		public void GetSponsorStickers()
		{
			int i;
			for (i = 0; i < sponsorStickerQuantity; i++)
				Console.WriteLine("  " + sponsorStickers[i]);
		}
		public void AddSponsorSticker(string newSponsorName)
		{
			Array.Resize(ref sponsorStickers, sponsorStickerQuantity + 1);
			sponsorStickers[sponsorStickerQuantity - 1] = newSponsorName;
		}
		public bool DeleteSponsorSticker(string nameDelete)
		{
			bool isStickerFound = false;
			int i, j;

			if (sponsorStickerQuantity != 0)
			{
				for (i = 0; i < sponsorStickerQuantity; i++)
					if (sponsorStickers[i] == nameDelete)
					{
						isStickerFound = true;
						for (j = i; j < sponsorStickerQuantity - 1; j++)
							sponsorStickers[j] = sponsorStickers[j + 1];
					}
				Array.Resize(ref sponsorStickers, sponsorStickerQuantity - 1);
				return true;
			}
			return false;
		}
		public void GetInfoTotalWear()
		{
			Console.WriteLine("Total Component Wear Ratio: " + seasonComponents.totalComponentWearRatio);
		}
		public void GetInfo()
		{
			GetInfoName();
			GetInfoDriverName();
			GetSponsorStickers();
			GetInfoTyreSet();
			GetInfoTotalWear();
			GetInfoCombastionEngine();
			GetInfoVehicleMguKinetic();
			GetInfoMguHeat();
			GetInfoTurboCharger();
			GetInfoEnergyStore();
			GetInfoControlElectronics();
			GetInfoPractiseGerbox();
			GetInfoEventGerbox();
		}
		public void GetInfoName()
		{
			Console.WriteLine("Vehicle Name: " + vehicleName);
		}
		public void GetInfoDriverName()
		{
			Console.WriteLine("Driver: " + driver.GetName());
		}
		public void GetInfoTyreSet()
		{
			switch (tyreSet.GetTyres())
			{
				case TyresCompound.NOT_INSTALLED:
					Console.WriteLine("Tyres aren't installed");
					break;
				case TyresCompound.SOFT:
					Console.ForegroundColor = ConsoleColor.Red; Console.Write("SOFT "); Console.ResetColor(); Console.WriteLine("tyres are installed");
					Console.WriteLine("  Tyre Wear: " + tyreSet.GetTyreWear());
					break;
				case TyresCompound.MEDIUM:
					Console.ForegroundColor = ConsoleColor.Yellow; Console.Write("MEDIUM "); Console.ResetColor(); Console.WriteLine("tyres are installed");
					Console.WriteLine("  Tyre Wear: " + tyreSet.GetTyreWear());
					break;
				case TyresCompound.HARD:
					Console.WriteLine("HARD tyres are installed");
					Console.WriteLine("  Tyre Wear: " + tyreSet.GetTyreWear());
					break;
			}
		}
		public void GetInfoCombastionEngine()
		{
			Console.Write("Internal Combastion Engine: ");
			switch (seasonComponents.powerUnitSet.internalCombastionEngine)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine2.GetWear());
					break;
				case InstalledComponent.COMPONENT_3:
					Console.WriteLine("3");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine3.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine3.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine3.GetWear());
					break;
			}
		}
		public void GetInfoVehicleMguKinetic()
		{
			Console.Write("MGU Kinetic: ");
			switch (seasonComponents.powerUnitSet.mguKinetic)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic2.GetWear());
					break;
				case InstalledComponent.COMPONENT_3:
					Console.WriteLine("3");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic3.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic3.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic3.GetWear());
					break;
			}
		}
		public void GetInfoMguHeat()
		{
			Console.Write("MGU Heat: ");
			switch (seasonComponents.powerUnitSet.mguHeat)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat2.GetWear());
					break;
				case InstalledComponent.COMPONENT_3:
					Console.WriteLine("3");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat3.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat3.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat3.GetWear());
					break;
			}
		}
		public void GetInfoTurboCharger()
		{
			Console.Write("Turbo Charger: ");
			switch (seasonComponents.powerUnitSet.turboCharger)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger2.GetWear());
					break;
				case InstalledComponent.COMPONENT_3:
					Console.WriteLine("3");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger3.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger3.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger3.GetWear());
					break;
			}
		}
		public void GetInfoEnergyStore()
		{
			Console.Write("Energy Store: ");
			switch (seasonComponents.powerUnitSet.energyStore)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.energyStore1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.energyStore1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.energyStore1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.energyStore2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.energyStore2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.energyStore2.GetWear());
					break;
			}
		}
		public void GetInfoControlElectronics()
		{
			Console.Write("Control Electronics: ");
			switch (seasonComponents.powerUnitSet.controlElectronics)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.controlElectronics1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.controlElectronics1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.controlElectronics1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.controlElectronics2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.controlElectronics2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.controlElectronics2.GetWear());
					break;
			}
		}
		public void GetInfoPractiseGerbox()
		{
			Console.Write("Practise Gearbox: ");
			switch (seasonComponents.gearboxSet.practiceGearbox)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox2.GetWear());
					break;
			}
		}
		public void GetInfoEventGerbox()
		{
			Console.Write("Event Gearbox: ");
			switch (seasonComponents.gearboxSet.eventGearbox)
			{
				case InstalledComponent.NOT_FITTED:
					Console.WriteLine("not fitted");
					break;
				case InstalledComponent.COMPONENT_1:
					Console.WriteLine("1");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.eventGearbox1.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.eventGearbox1.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.eventGearbox1.GetWear());
					break;
				case InstalledComponent.COMPONENT_2:
					Console.WriteLine("2");
					Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.eventGearbox2.GetExpectedLifespan());
					Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.eventGearbox2.GetTrackTime());
					Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.eventGearbox2.GetWear());
					break;
			}
		}
		public void SetName(string newName)
		{
			vehicleName = newName;
		}
		public void SetTyres_interface()
		{
			bool isPass, isCycled;
			int decision;

			do
			{
				isCycled = true;
				Console.Clear();
				Console.ForegroundColor = ConsoleColor.Green;
				Console.WriteLine("Current Tyres: ");
				Console.ResetColor();

				switch (tyreSet.GetTyres())
				{
					case TyresCompound.NOT_INSTALLED:
						Console.WriteLine(" Tyres aren't installed");
						break;
					case TyresCompound.SOFT:
						Console.ForegroundColor = ConsoleColor.Red;
						Console.Write("SOFT ");
						Console.ResetColor();
						Console.Write("tyres are installed");
						Console.WriteLine(" Tyre Wear: " + tyreSet.GetTyreWear());
						break;
					case TyresCompound.MEDIUM:
						Console.ForegroundColor = ConsoleColor.Yellow;
						Console.Write("MEDIUM ");
						Console.ResetColor();
						Console.Write("tyres are installed");
						Console.WriteLine(" Tyre Wear: " + tyreSet.GetTyreWear());
						break;
					case TyresCompound.HARD:
						Console.Write("HARD tyres are installed");
						Console.WriteLine(" Tyre Wear: " + tyreSet.GetTyreWear());
						break;
				}

				Console.ForegroundColor = ConsoleColor.Green;
				Console.WriteLine("Available options: ");
				Console.ResetColor();

				Console.Write("  1) ");
				Console.ForegroundColor = ConsoleColor.Red;
				Console.WriteLine("SOFT");
				Console.ResetColor();

				Console.Write("  2) ");
				Console.ForegroundColor = ConsoleColor.Yellow;
				Console.WriteLine("MEDIUM");
				Console.ResetColor();
				Console.WriteLine("  3) HARD");

				Console.Write("\nPick Option (0 - return): ");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if ((decision >= 1 && decision <= 3) || decision == 0)
						isPass = true;
				} while (isPass == false);

				switch (decision)
				{
					case 1:
						tyreSet.SetTyres(TyresCompound.SOFT);
						break;
					case 2:
						tyreSet.SetTyres(TyresCompound.MEDIUM);
						break;
					case 3:
						tyreSet.SetTyres(TyresCompound.HARD);
						break;
					case 0:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}
		public void SetComponents_interface()
		{
			bool isPass, isCycled;
			int decision;

			do
			{
				isCycled = true;
				Console.Clear();

				Console.ForegroundColor = ConsoleColor.Green;
				Console.WriteLine("Current Components Info:\n");


				Console.WriteLine("Power Unit:");
				Console.ResetColor();

				Console.Write("1) "); GetInfoCombastionEngine();
				Console.Write("2) "); GetInfoVehicleMguKinetic();
				Console.Write("3) "); GetInfoMguHeat();
				Console.Write("4) "); GetInfoTurboCharger();
				Console.Write("5) "); GetInfoEnergyStore();
				Console.Write("6) "); GetInfoControlElectronics();

				Console.ForegroundColor = ConsoleColor.Green;
				Console.WriteLine("\nGearbox:");
				Console.ResetColor();

				Console.Write("7) "); GetInfoPractiseGerbox();
				Console.Write("8) "); GetInfoEventGerbox();

				Console.Write("\nPick component you want to change (0 - return)...");

				do
				{
					isPass = false;
					decision = Convert.ToInt32(Console.ReadLine());
					if ((decision >= 1 && decision <= 8) || decision == 0)
						isPass = true;
				} while (isPass == false);
				Console.Clear();

				switch (decision)
				{
					case 1:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Internal Combastion Engine:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine2.GetWear());
						Console.WriteLine("3:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.engine3.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.engine3.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.engine3.GetWear());

						Console.Write("\nPick Engine you want to fit or press 4 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 4) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent.COMPONENT_3;
									break;
								case 4:
									seasonComponents.powerUnitSet.internalCombastionEngine = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 2:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("MGU Kinetic:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.ResetColor();
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic2.GetWear());
						Console.WriteLine("3:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguKinetic3.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguKinetic3.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguKinetic3.GetWear());

						Console.Write("\nPick MGU Kinetic you want to fit or press 4 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 4) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.mguKinetic = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.mguKinetic = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.mguKinetic = InstalledComponent.COMPONENT_3;
									break;
								case 4:
									seasonComponents.powerUnitSet.mguKinetic = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 3:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("MGU Heat:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat2.GetWear());
						Console.WriteLine("3:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.mguHeat3.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.mguHeat3.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.mguHeat3.GetWear());

						Console.Write("\nPick MGU Heat you want to fit or press 4 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 4) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.mguHeat = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.mguHeat = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.mguHeat = InstalledComponent.COMPONENT_3;
									break;
								case 4:
									seasonComponents.powerUnitSet.mguHeat = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 4:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Turbo Charger:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger2.GetWear());
						Console.WriteLine("3:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.turboCharger3.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.turboCharger3.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.turboCharger3.GetWear());

						Console.Write("\nPick Turbo Charger you want to fit or press 4 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 4) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.turboCharger = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.turboCharger = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.turboCharger = InstalledComponent.COMPONENT_3;
									break;
								case 4:
									seasonComponents.powerUnitSet.turboCharger = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 5:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Energy Store:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.energyStore1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.energyStore1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.energyStore1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.energyStore2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.energyStore2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.energyStore2.GetWear());

						Console.Write("\nPick Energy Store you want to fit or press 3 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 3) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.energyStore = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.energyStore = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.energyStore = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 6:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Control Electronics:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.controlElectronics1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.controlElectronics1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.controlElectronics1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.powerUnitSet.controlElectronics2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.powerUnitSet.controlElectronics2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.powerUnitSet.controlElectronics2.GetWear());

						Console.Write("\nPick Control Electronics you want to fit or press 3 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 3) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.powerUnitSet.controlElectronics = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.powerUnitSet.controlElectronics = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.powerUnitSet.controlElectronics = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 7:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Practise Gearbox:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox2.GetWear());

						Console.Write("\nPick Practise Gearbox you want to fit or press 3 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 3) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.gearboxSet.practiceGearbox = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.gearboxSet.practiceGearbox = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.gearboxSet.practiceGearbox = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 8:
						Console.ForegroundColor = ConsoleColor.Green;
						Console.WriteLine("Event Gearbox:");
						Console.ResetColor();
						Console.WriteLine("1:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox1.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox1.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox1.GetWear());
						Console.WriteLine("2:");
						Console.WriteLine("  Expected Lifespan: " + seasonComponents.gearboxSet.practiceGearbox2.GetExpectedLifespan());
						Console.WriteLine("  Track Time: " + seasonComponents.gearboxSet.practiceGearbox2.GetTrackTime());
						Console.WriteLine("  Wear: " + seasonComponents.gearboxSet.practiceGearbox2.GetWear());

						Console.Write("\nPick Event Gearbox you want to fit or press 3 to take off the fitted component (0 - return)...");

						do
						{
							isPass = false;
							decision = Convert.ToInt32(Console.ReadLine());
							if ((decision >= 1 && decision <= 3) || decision == 0)
								isPass = true;
						} while (isPass == false);

						if (decision != 0)
							switch (decision)
							{
								case 1:
									seasonComponents.gearboxSet.eventGearbox = InstalledComponent.COMPONENT_1;
									break;
								case 2:
									seasonComponents.gearboxSet.eventGearbox = InstalledComponent.COMPONENT_2;
									break;
								case 3:
									seasonComponents.gearboxSet.eventGearbox = InstalledComponent.NOT_FITTED;
									break;
								case 0:
									break;
							}
						break;
					case 0:
						isCycled = false;
						break;
				}
			} while (isCycled);
		}
		public void SetDriver(Driver newDriver)
		{
			driver = newDriver;
		}
		public void SetTotalComponentWearRatio(int aerodynamicsLevel, int powertrainLevel, int chassisLevel, int durabilityLevel)
		{
			double tempTotalWear = seasonComponents.totalComponentWearRatio;

			tempTotalWear = tempTotalWear * 10;

			tempTotalWear = tempTotalWear - aerodynamicsLevel - powertrainLevel - chassisLevel - durabilityLevel;

			tempTotalWear = tempTotalWear / 10;

			seasonComponents.totalComponentWearRatio = tempTotalWear;
		}
	}
}
