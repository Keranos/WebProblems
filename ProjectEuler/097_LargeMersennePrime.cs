using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrunkScratchPad
{
    public sealed class LargeMersennePrime_97
    {
        public void Solve()
        {
            ulong result = 1;

            var exponent = 7830457;
            ulong num = 28433;

            for (int i = 1; i <= exponent; i++)
            {
                result *= 2;
                result = result%10000000000;
            }

            result *= num;
            result += 1;

            Console.WriteLine(result);
        }
    }
}
