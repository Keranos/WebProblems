// What is the largest n-digit pandigitial prime that exist?

#include <iostream>
#include <vector>

#include "MathFunctions.h"

typedef std::vector<int> vec;

int main(){
  vec primes = get_primes_below(7654321);
  
  for(vec::reverse_iterator i = primes.rbegin(); i != primes.rend(); ++i)
    if(is_pandigital(*i)){
      std::cout << *i << std::endl;
      break;
    }
}
