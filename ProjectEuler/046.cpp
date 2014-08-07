// What is the smallest odd composite that cannot be written as the sum
// of a prime and twice a square?

#include <iostream> 
#include <cmath>

#include "MathFunctions.h"

bool is_Goldbach(const unsigned long& n){
  unsigned long s = (unsigned long)sqrt(n);
  unsigned long t = n;

  for(int i = 1; i <= s; ++i){
    t -= 2*i*i;
    if(is_prime(t))
      return true;
    t = n;
  }
  
  return false;
}

int main(){
  unsigned long n = 3;
  
  while(true){
    if(!is_prime(n)){
      if(!is_Goldbach(n)){
	std::cout << n << std::endl;
	break;
      }
    }
    n += 2;
  }
}
