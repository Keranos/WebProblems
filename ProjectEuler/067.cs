using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MathLib.Curves;

namespace TrunkScratchPad
{
    public sealed class MaximumPathSum067
    {
        public void Solve()
        {
            var file = new System.IO.StreamReader(@"C:\Users\csmith\Downloads\p067_triangle.txt");
            string line;
            var n = 100;
            var grid = new int[n, n];
            int k = 0;

            while ((line = file.ReadLine()) != null)
            {
                var bits = line.Split(' ');
                for (int j = 0; j < bits.Length; j++)
                    grid[k, j] = int.Parse(bits[j]);

                k++;
            }

            for (int i = n - 1; i > 0; i--)
                for (int j = 0; j < i; j++)
                {
                    var v1 = grid[i, j] + grid[i - 1, j];
                    var v2 = grid[i, j + 1] + grid[i - 1, j];
                    grid[i - 1, j] = v1 > v2 ? v1 : v2;
                }

            Console.WriteLine(grid[0, 0]);
        }
    }
}
