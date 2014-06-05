#include <iostream>
#include <iomanip>
#include <math.h>

int main(){
  long double x1, x2, x3, y1, y2, y3;
  long double h, k, r;
  long double ln, rn, ld, rd;
  long double xx, yy;
  while(std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3){
    ln = x3*x3-x1*x1+y3*y3-y1*y1;
    rn = x2*x2-x1*x1+y2*y2-y1*y1;
    ld = (x3-x1)*(y2-y1);
    rd = (x2-x1)*(y3-y1);
    h = ((y2-y1)*ln - (y3-y1)*rn)/(2*(ld-rd));
    k = ((x2-x1)*ln - (x3-x1)*rn)/(2*(rd-ld));
    xx = (x1-h)*(x1-h);
    yy = (y1-k)*(y1-k);
    r = sqrt(xx+yy);
    std::cout << std::fixed << std::setprecision(2) << 2*3.14159*r << std::endl;
  }
}
