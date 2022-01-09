// Spiral primes. Read description online

#include <iostream>
#include "MathFunctions.h"

int main(){
  int count = 0;
  double ratio = 1.0;
  int row = 0;
  int f0 = 1;

  while(ratio > 0.1){
    row++;
    int fn = f0 + (2 + (row-1)*8);
    for(int i = 0; i < 4; ++i){
      if(is_prime(fn + i*(row)*2))
	count++;
      
    }
    f0 = fn;
    ratio = count / (4.0*row);
  }

  std::cout << row*2+1 << std::endl;
}
