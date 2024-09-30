using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp2
{
    enum TyresCompound
    {
        NOT_INSTALLED,
        SOFT,
        MEDIUM,
        HARD
    }
    internal class Tyres
    {
        TyresCompound installedTyres;
        int tyreWear;


        public Tyres()
        {
            installedTyres = TyresCompound.NOT_INSTALLED;
        }

        public int GetTyreWear()
        {
            return tyreWear;
        }
        public void SetTyres(TyresCompound newTyres)
        {
            installedTyres = newTyres;
            tyreWear = 0;
        }
        public TyresCompound GetTyres()
        {
            return installedTyres;
        }
    }
}
