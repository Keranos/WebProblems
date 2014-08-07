// Find the sum of the only eleven primes that are both truncable from 
// left to right and right to left.

#include <iostream>

#include "MathFunctions.h"

bool truncatable_prime(const unsigned long& n){
  int ten = 1;
  int front = n;
  int back = 0;

  while(front > 0){
    int r = front % 10;
    back += ten * r;
    front /= 10;

    ten *= 10;

    if(front > 0 && (!is_prime(back) || !is_prime(front)))
      return false;
  }
  
  return true;
}

int main(){
  int n = 7;
  int count = 0;
  int result = 0;

  while (count < 11){
    n = next_prime(n);
    if(truncatable_prime(n)){ 
      result += n;
      count++;
    }
  }

  std::cout << result << std::endl;
}
