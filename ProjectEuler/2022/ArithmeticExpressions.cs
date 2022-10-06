using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SolveProblems
{
    public sealed class ArithmeticExpressions
    {
        public static void Solve()
        {
            var input = new HashSet<int> { 4, 3, 5, 7, 8, 9, 10, 1, 6 };
            var length = LongestConsecutive(input);

            for (int a = 1; a < 7; ++a)
                for (int b = a + 1; b < 8; ++b)
                    for (int c = b + 1; c < 9; ++c)
                        for (int d = c + 1; d < 10; ++d)
                        { 
                            
                        }
        }

        private static bool IsInt(double d)
        {
            return Math.Abs(d % 1) <= (Double.Epsilon * 100);
        }

        private static int LongestConsecutive(HashSet<int> values)
        {
            int bestLength = 0;

            while (values.Count > 0)
            {
                int value = values.First();
                values.Remove(value);
                
                int start = value;
                while (values.Remove(start - 1))
                {
                    start--;
                }

                int end = value;
                while (values.Remove(end + 1))
                {
                    end++;
                }

                int length = end - start + 1;

                if (length > bestLength)
                    bestLength = length;
            }

            return bestLength;
        }
    }
}
