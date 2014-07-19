#include <iostream>

#include "MathFunctions.h"

int main(){
  int nPrimes = 1;
  int n = 1;

  while(nPrimes < 10001){
    n += 2;
    if(is_prime(n)) 
      nPrimes++;
  }

  std::cout << n << std::endl;
}
