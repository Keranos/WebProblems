#include <math.h>
#include <iostream>

const double comp = 0.21460183660255169;

double calc_y(int n){
  double num = n + 1 - sqrt(2.0*n);
  double den = n*n + 1;
  return num/den;
}

double rectangle(int n){
  double y = calc_y(n);
  return y * y * n / 2.0; 
}

double calc_theta(int n){
  return asin(calc_y(n) * n - 1.0);
}

double value(int n){
  double rec = rectangle(n);
  double theta = calc_theta(n);
  double v = rec + theta/2.0 - sin(theta) + 0.25*sin(2.0*theta);
  return v;
}

int main(){
  int i = 1;
  while(true){
    i++;
    double ratio = value(i) / comp;
    if(ratio < 0.001)
      break;
  }

  std::cout << i << std::endl;
}
