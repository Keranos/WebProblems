// Ellipse defined as 4x^2 + y^2 = 100. Small slit at the top.
// Laser comes in and bounces around. How many bounces before it flies out?

#include <math.h>
#include <iostream>

int main(){
  int r = 0;
  
  double xa = 0.0;
  double ya = 10.1;
  
  double x0 = 1.4;
  double y0 = -9.6;
  
  while(x0 > 0.01 || x0 < -0.01 || y0 < 0){
    double ma = (y0 - ya) / (x0 - xa);
    double m0 = -4.0 * x0 / y0; // tangent slope
    double tana = (ma - m0) / (1.0 + ma * m0);
    double mb = (m0 - tana) / (1.0 + tana * m0);
    
    double newx = (x0 * (mb*mb - 4) - 2*mb*y0) / (mb*mb + 4);
    double newy = mb*(newx - x0) + y0;
    
    xa = x0; ya = y0;
    x0 = newx; y0 = newy;
    
    r++;
  }
  std::cout << r << std::endl;
}
