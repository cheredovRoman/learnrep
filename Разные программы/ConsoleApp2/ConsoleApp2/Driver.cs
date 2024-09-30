using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Driver
	{
		string name;
		int number;

		int overallRating;
		int experience;
		int racecraft;
		int awareness;
		int pace;
		double salary;


		public Driver()
		{
			name = "NoName";
			number = 0;

			overallRating = 0;
			experience = 0;
			racecraft = 0;
			awareness = 0;
			pace = 0;
			salary = 0;
		}

		public void SetName(string newName)
		{
			name = newName;
		}
		public void SetNumber(int newNumber)
		{
			number = newNumber;
		}
		public void SetOverallRating(int newOverallRating)
		{
			overallRating = newOverallRating;
		}
		public void SetExperience(int newExperience)
		{
			experience = newExperience;
		}
		public void SetRacecraft(int newRacecraft)
		{
			racecraft = newRacecraft;
		}
		public void SetAwareness(int newAwareness)
		{
			awareness = newAwareness;
		}
		public void SetPace(int newPace)
		{
			pace = newPace;
		}
		public void SetSalary(double newSalary)
		{
			salary = newSalary;
		}
		public void GetInfo()
		{
			Console.ForegroundColor = ConsoleColor.Green;
			Console.Write("Driver ");
			Console.ResetColor();

			Console.WriteLine(name + " " + number);
			Console.WriteLine("    " + "Overall rating: " + overallRating);
			Console.WriteLine("    " + "Experience: " + experience);
			Console.WriteLine("    " + "Racecraft: " + racecraft);
			Console.WriteLine("    " + "Awareness: " + awareness);
			Console.WriteLine("    " + "Pace: " + pace);
			Console.WriteLine("    " + "Salary: " + salary);
		}
		public string GetName()
		{
			return name;
		}
		public bool isDriverHired()
		{
			if (name == "NoName")
				return false;
			else
				return true;
		}
		public string returnDriverName()
		{
			return name;
		}
	}
}
