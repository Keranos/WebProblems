// Find the first Fibonacci number to have 1000 digits
// We can solve this with a little bit of math. 
// The Fibonacci sequence converges to F(n) = [ \phi^n / \sqrt(5) ]

#include <iostream>
#include <math.h>

int main(){
  const double phi = 1.61803398875;
  
  double n = (log10(10) * 999.0 + log10(5) / 2.0 ) / log10(phi);
  
  std::cout << ceil(n) << std::endl;
}
