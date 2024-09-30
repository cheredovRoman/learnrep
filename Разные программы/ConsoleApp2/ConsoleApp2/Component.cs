using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
	public enum InstalledComponent
	{
		NOT_FITTED,
		COMPONENT_1,
		COMPONENT_2,
		COMPONENT_3
	};

	public enum ComponentID
	{
		Engine,
		MguKinetic,
		MguHeat,
		TurboCharger,
		EnergyStore,
		ControlElectronics,
		Gearbox
	};

	internal class Component
	{
		int expectedLifespan;
		int trackTime;
		int wear;

		public Component(ComponentID componentName)
		{
			switch (componentName)
			{
				case ComponentID.Engine:
					expectedLifespan = 340;
					break;
				case ComponentID.MguKinetic:
					expectedLifespan = 800;
					break;
				case ComponentID.MguHeat:
					expectedLifespan = 700;
					break;
				case ComponentID.TurboCharger:
					expectedLifespan = 500;
					break;
				case ComponentID.EnergyStore:
					expectedLifespan = 900;
					break;
				case ComponentID.ControlElectronics:
					expectedLifespan = 450;
					break;
				case ComponentID.Gearbox:
					expectedLifespan = 380;
					break;
			}
		}

		public int GetExpectedLifespan()
		{
			return expectedLifespan;
		}
		public int GetTrackTime()
		{
			return trackTime;
		}
		public int GetWear()
		{
			return wear;
		}
		public void SetExpectedLifespan(int newExpectedLifespan)
		{
			expectedLifespan = newExpectedLifespan;
		}
		public void SetTrackTime(int newTrackTime)
		{
			trackTime = newTrackTime;
		}
		public void SetWear(int newWear)
		{
			wear = newWear;
		}
	}
}
