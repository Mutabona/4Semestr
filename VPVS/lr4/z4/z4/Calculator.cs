using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace z4
{
    internal class Calculator
    {
        public double Calculate(double x, double y)
        {
            double d = 0;

            if (x > y)
            {
                d = Math.Pow(Math.Sinh(x) - y, 3) + Math.Atan(Math.Sinh(x));
            }
            else if (y > x)
            {
                d = Math.Pow(y - Math.Sinh(x), 3) + Math.Atan(Math.Sinh(x));
            }
            else
            {
                d = Math.Pow(y + Math.Sinh(x), 3) + 0.5;
            }

            return d;
        }
    }
}
