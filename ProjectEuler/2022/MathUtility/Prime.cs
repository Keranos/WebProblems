using System;

namespace SolveProblems.MathUtility
{
    public sealed class Prime
    {
        public static bool IsPrime(int n)
        {
            if (n == 1) return false;
            if (n == 2) return false;
            if (n % 2 == 0) return false;

            var limit = Math.Floor(Math.Sqrt(n));

            for (int i = 3; i <= limit; i += 2)
                if (n % i == 0)
                    return false;

            return true;
        }
    }
}
