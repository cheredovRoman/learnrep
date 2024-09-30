using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace kursovayach
{
    class User
    {
        protected string name;
        public string username()
        {
            return name;
        }
    }
    public class Doctor : User
    {
        public Doctor(string name)
        {
            this.name = name;
        }
    }
}
