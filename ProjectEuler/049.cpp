// The arithmetic sequence 1487, 4817, 8147, in which each of the terms 
// increases by 3330, is unusual in two ways: each is a prime, each 
// is a permutation of the other. Find the other four digit number which 
// has this property.

#include <iostream>
#include <vector>
#include <algorithm>

#include "MathFunctions.h"

int main(){
  const int max = 10000;
  std::vector<int> primes;

  for(int i = 1489; i < max; ++i)
    if(is_prime(i))
      primes.push_back(i);

  for(int i = 0; i < primes.size(), primes[i] < 3333; ++i)
    for(int j = i + 1; j < primes.size(); ++j){
      int k = 2*primes[j] - primes[i];
      if(k < max && std::find(primes.begin(), primes.end(), k) != primes.end())
	if(same_digits(primes[i], primes[j]) && same_digits(primes[i], k))
	  std::cout << primes[i] << primes[j] << k << std::endl;
    }
}
