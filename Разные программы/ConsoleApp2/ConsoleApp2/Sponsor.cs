using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	enum SponsorTargetRace
	{
		PODIUM,
		TOP_5,
		TOP_10,
		FINISH
	}

	enum SponsorTargetSeason
	{
		CHAMP,
		TOP_THREE,
		TOP_FIVE,
		EVERY_RACE_PARTICIPATE,
		NOT_LAST
	}

	internal class Sponsor
	{

		private string name;
		private SponsorTargetRace targetRace;
		private SponsorTargetSeason targetSeason;
		private double paymentPerRace;
		private double targetBonusRatio;

		public Sponsor()
		{
			name = "NoName";
			targetRace = SponsorTargetRace.FINISH;
			targetSeason = SponsorTargetSeason.NOT_LAST;
			paymentPerRace = 0;
			targetBonusRatio = 1;
		}

		public void SetName(string newName)
		{
			name = newName;
		}

		public void SetTargetRace_interface()
		{
			bool isPass;
			int decision;

			Console.WriteLine("1) Podium");
			Console.WriteLine("2) TOP 5");
			Console.WriteLine("3) TOP 10");
			Console.WriteLine("4) To Finish\n");
			Console.Write("Select sponsor's target for the race: ");

			do
			{
				isPass = false;
				decision = Convert.ToInt32(Console.ReadLine());
				if (decision >= 1 && decision <= 4)
					isPass = true;
			} while (isPass == false);

			switch (decision)
			{
				case 1:
					targetRace = SponsorTargetRace.PODIUM;
					break;
				case 2:
					targetRace = SponsorTargetRace.TOP_5;
					break;
				case 3:
					targetRace = SponsorTargetRace.TOP_10;
					break;
				case 4:
					targetRace = SponsorTargetRace.FINISH;
					break;
			}
		}
		public void SetTargetSeason_interface()
		{
			bool isPass;
			int decision;

			Console.WriteLine("1) One of the driver is champion");
			Console.WriteLine("2) TOP 3");
			Console.WriteLine("3) TOP 5");
			Console.WriteLine("4) Finish every race");
			Console.WriteLine("5) Not last in the season\n");
			Console.Write("Select sponsor's target for the season: ");

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
					targetSeason = SponsorTargetSeason.CHAMP;
					break;
				case 2:
					targetSeason = SponsorTargetSeason.TOP_THREE;
					break;
				case 3:
					targetSeason = SponsorTargetSeason.TOP_FIVE;
					break;
				case 4:
					targetSeason = SponsorTargetSeason.EVERY_RACE_PARTICIPATE;
					break;
				case 5:
					targetSeason = SponsorTargetSeason.NOT_LAST;
					break;
			}
		}
		public void SetPaymentPerRace(double newPaymentPerRace)
		{
			paymentPerRace = newPaymentPerRace;
		}
		public void SetTargetBonusRatio(double newTargetBonusRatio)
		{
			targetBonusRatio = newTargetBonusRatio;
		}
		public void GetInfoSponsor()
		{
			Console.WriteLine("Sponsor " + name);

			Console.Write("\nRace Target: ");
			switch (targetRace)
			{
				case SponsorTargetRace.PODIUM:
					Console.WriteLine("Podium");
					break;
				case SponsorTargetRace.TOP_5:
					Console.WriteLine("TOP 5");
					break;
				case SponsorTargetRace.TOP_10:
					Console.WriteLine("TOP 10");
					break;
				case SponsorTargetRace.FINISH:
					Console.WriteLine("Cross the finish line");
					break;
			}

			Console.Write("Season Target: ");
			switch (targetSeason)
			{
				case SponsorTargetSeason.CHAMP:
					Console.WriteLine("One of the drivers is champion");
					break;
				case SponsorTargetSeason.TOP_THREE:
					Console.WriteLine("TOP 3");
					break;
				case SponsorTargetSeason.TOP_FIVE:
					Console.WriteLine("TOP 5");
					break;
				case SponsorTargetSeason.NOT_LAST:
					Console.WriteLine("Not Last");
					break;
			}

			Console.WriteLine("Income per race: " + paymentPerRace);

			Console.WriteLine("Target bonus ratio: " + targetBonusRatio);
		}
		public double GetPaymentPerRace()
		{
			return paymentPerRace;
		}
	}
}
