// How many circular primes are there below one million?

#include <iostream>
#include <vector>
#include <algorithm>

#include "MathFunctions.h"

typedef std::vector<int> vec;

bool is_circular_prime(const int& n, const vec& primes){
  int count = 0;
  int multiplier = 1;
  int t = n;

  while(t > 0){
    int m = t % 10;
    if(m % 2 == 0 || m == 5) return false;
    count++;
    t /= 10;
    multiplier *= 10;
  }
  
  multiplier /= 10;
  
  t = n;
  for(int i = 0; i < count; ++i){
    if(std::find(primes.begin(), primes.end(), t) == primes.end())
      return false;

    int m = t % 10;
    t = m * multiplier + t / 10;
  }

  return true;
}

int main(){
  vec p = get_primes_below(1000000);

  int count = 2; 
  for(vec::iterator i = p.begin(); i != p.end(); ++i)
    if(is_circular_prime(*i, p)) 
      count++;
  
  std::cout << count << std::endl;
}
