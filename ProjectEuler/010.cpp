#include <iostream>

#include "MathFunctions.h"

int main(){
  unsigned long int total = 2;
  unsigned long int n = 1;

  while(n < 2000000){
    n += 2;
    if(is_prime(n)) 
      total += n;
  }

  std::cout << total << std::endl;
}
