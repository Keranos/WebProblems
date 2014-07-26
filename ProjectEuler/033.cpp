// Find the four 2 digit fraction such that 49/98 => 4/8 holds true. 
// Give the denominator of the product of these fractions in lowest
// common terms. 

// We can simplify this greatly to simply solving the following:
// (10n + i) / (10i + d) == n / d where n > d > i;

#include <iostream>

#include "MathFunctions.h"

int main(){
  int rd = 1;
  int nd = 1;
  
  for(int i = 3; i < 10; ++i)
    for(int d = 2; d < i; ++d)
      for(int n = 1; n < d; ++n)
	if( (n*10 + i)*d == n*(i*10 + d) ){
	  rd *= d;
	  nd *= n;
	}

  std::cout << rd/gcd(rd, nd) << std::endl;
}
