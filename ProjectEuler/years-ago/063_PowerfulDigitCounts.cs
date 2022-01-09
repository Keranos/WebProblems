using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrunkScratchPad
{
    public sealed class PowerfulDigitCounts_63
    {
        public void Solve()
        {
            var n = 1;
            var lower = 0;
            var result = 0;

            while (lower < 10)
            {
                lower = Convert.ToInt32(Math.Ceiling(Math.Pow(10, (n - 1.0)/n)));
                result += 10 - lower;
                n++;
            }

            Console.WriteLine(result);
        }
    }
}
