using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	internal class Bureau
	{
		int level;
		double fabrication;
		double buildTime;
		double qualityControl;
		double resourcePointGeneration;
		public Bureau()
		{
			level = 1;
			fabrication = 1;
			buildTime = 1;
			qualityControl = 0.2;
			resourcePointGeneration = 1;
		}

		public int GetLevel()
		{
			return level;
		}
		public double GetFabrication()
		{
			return fabrication;
		}
		public double GetBuildTime()
		{
			return buildTime;
		}
		public double GetQualityControl()
		{
			return qualityControl;
		}
		public double GetResourcePointGeneration()
		{
			return resourcePointGeneration;
		}
		public void UpgradeBureau()
		{
			level++;
			fabrication = fabrication - 0.15;
			buildTime = buildTime - 0.15;
			qualityControl = qualityControl - 0.06;
			resourcePointGeneration = resourcePointGeneration + 0.2;
		}
	}
}
