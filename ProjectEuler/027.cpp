// Find the product of the coefficients, a and b, for the quadratic expression
// that produces the maximum number of primes for consecutive value of n

#include <iostream>
#include <vector>

#include "MathFunctions.h"

typedef std::vector<int> vec;

int main(){
  int result = 0;
  int max_primes = 0;
  vec primes = get_primes_below(1000);

  for (int a = -999; a < 1000; a += 2)
    for(vec::iterator b = primes.begin(); b != primes.end(); ++b){
      int n = 0;
      while(is_prime(n*n + a*n + (*b)))
	n++;

      if(n > max_primes){
	max_primes = n;
	result = a * (*b);
      }
    }
  
  std::cout << max_primes << std::endl;
  std::cout << result << std::endl;
}
