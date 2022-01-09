#include <iostream>
#include <math.h>

#include "MathFunctions.h"

const unsigned long long int n = 600851475143ULL;
const unsigned long max = 775146;

int main(){
  for(unsigned long int i = 1; i < max; ++i)
    if(is_prime(i))
      if(n % i == 0)
	std::cout << i << std::endl;
}

