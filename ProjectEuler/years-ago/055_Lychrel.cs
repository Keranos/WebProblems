using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.RightsManagement;
using System.Text;
using System.Threading.Tasks;

namespace TrunkScratchPad
{
    public sealed class Lychrel_55
    {
        public void Solve()
        {
            var count = 0;
            ulong n = 10000;

            ulong i = 1;

            while (i < n)
            {
                var iteration = 1;
                var number = i;
                var stay = true;

                while (stay && iteration < 50)
                {
                    iteration++;
                    number += Reverse(number);
                    if (IsPalindrome(number))
                    {
                        count++;
                        stay = false;
                    }
                }

                i++;
            }

            Console.WriteLine(9999-count);
        }

        private ulong Reverse(ulong num)
        {
            ulong result = 0;
            while (num > 0)
            {
                result = result*10 + num%10;
                num /= 10;
            }

            return result;
        }

        private bool IsPalindrome(ulong num)
        {
            string sNum = num.ToString();
            for (int i = 0; i < sNum.Length/2; i++)
                if (sNum[i] != sNum[sNum.Length - 1 - i]) return false;

            return true;
        }
    }
}
