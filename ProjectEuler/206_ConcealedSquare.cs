using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrunkScratchPad.Euler
{
    public sealed class ConcealedSquare206
    {
        public void Solve()
        {
            ulong lowerLimit = Convert.ToUInt64(Math.Sqrt(1020304050607080900))/10;
            ulong upperLimit = Convert.ToUInt64(Math.Sqrt(1929394959697989990))/10 + 1;
            ulong solution = 0;

            for (ulong i = lowerLimit; i < upperLimit; i++)
            {
                if (CheckForm(i*i*100))
                    solution = i*10;
            }

            Console.WriteLine(solution);
        }

        private bool CheckForm(ulong n)
        {
            for (ulong i = 0; i < 10; i++)
            {
                if (n%10 != (i == 0 ? 0 : 10 - i))
                    return false;

                n /= 100;
            }

            return true;
        }
    }
}
