using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrunkScratchPad
{
    public sealed class SquareDigitChains_92
    {
        public void Solve()
        {
            var i = 2;
            while (i < 10000000)
            {
                var current = i;
                var chain = new HashSet<int>{current};

                while (!_one.Contains(current) && !_eightyNine.Contains(current))
                {
                    current = SquareDigits(current);
                    chain.Add(current);
                }

                if (_one.Contains(current))
                    _one.UnionWith(chain);
                else
                    _eightyNine.UnionWith(chain);

                i++;
            }

            Console.WriteLine(_eightyNine.Count);
        }

        public int SquareDigits(int i)
        {
            var result = 0;
            while (i > 0)
            {
                var n = i%10;
                result += n*n;
                i /= 10;
            }

            return result;
        }

        private readonly HashSet<int> _one = new HashSet<int> {1};
        private readonly HashSet<int> _eightyNine = new HashSet<int> {89}; 
    }
}
