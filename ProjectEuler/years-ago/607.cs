using System;

namespace TrunkScratchPad
{
    public class AutoDiff
    {
        public class Point
        {
            // create a new 2D point
            public Point(double x, double y)
            {
                X = x;
                Y = y;
            }

            public double X;
            public double Y;

            // distance between two points
            public double Distance(Point other)
            {
                var diffX = X - other.X;
                var diffY = Y - other.Y;
                return Math.Sqrt(diffX * diffX + diffY * diffY);
            }
        }

        // how many days does it take to walk from the first to the last point, considering "speed" of the surfaces
        public static double Duration(Point[] points)
        {
            var speed = new[] { 10.0, 9, 8, 7, 6, 5, 10 };

            double result = 0;
            for (var i = 0; i < speed.Length; i++)
            {
                var way = points[i].Distance(points[i + 1]);
                result += way / speed[i];
            }
            return result;
        }

        public static Random rand = new Random();

        // try to move a single point's y-value by delta
        // if the mutation is better, then keep the result
        // if the mutation is worse,  then undo the change
        public static void mutate(Point[] points, double delta)
        {
            var oldDuration = Duration(points);

            // decide at random whether to add or subtract
            if (rand.NextDouble() > 0.5)
                delta = -delta;

            // change one random y-coordinate (must not be the first or last)
            var id = rand.Next() % 6 + 1;
            points[id].Y += delta;

            // not faster ? => undo change
            if (Duration(points) >= oldDuration)
                points[id].Y -= delta;
        }

        public static void Run()
        {

            var points = new Point[8];
            points[0] = new Point(0, 0);

            // rotate the coordinate system by 45 degrees,
            // so that travelling one league is equivalent to moving 1/scaling units along x-axis and 1/scaling units along y-axis
            double scaling = Math.Sqrt(2);

            // when travelling the shortest distance between A and B, how wide is the marsh ?
            var direct = 50 * scaling; // c^2 = a^2 + b^2 where a=b=50

            // entering the marsh
            var current = ((100 - direct) / 2) / scaling; // same as 25*(sqrt(2)-1)
            points[1] = new Point(current, current);

            // all 5 zones of the marsh
            for (var i = 1; i <= 5; i++)
                points[i + 1] = new Point(current + i * 10, current + i * 10);

            // B
            points[7] = new Point(100 / scaling, 100 / scaling);

            // randomly mutate the crossing
            const int NumIterations = 100000;
            for (var delta = 0.01; delta >= 0.00001; delta /= 10)
                for (var i = 0; i < NumIterations; i++)
                    mutate(points, delta);

            // display result with 10 digits after the decimal point
            Console.WriteLine(Duration(points));
        }
    }
}
