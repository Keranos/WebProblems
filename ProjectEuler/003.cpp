#include <iostream>
#include <math.h>

const unsigned long long int n = 600851475143ULL;
const unsigned long max = 775146;

int IsPrime(unsigned int n)
{
  if(n <= 1) return 0;
  unsigned int i;
  for(i = 2; i < sqrt(n); ++i)
    if(n % i == 0) 
      return 0;
  return 1;
}

int main(){
  for(unsigned long int i = 1; i < max; ++i)
    if(IsPrime(i))
      if(n % i == 0)
	std::cout << i << std::endl;
}

