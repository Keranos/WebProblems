// Find the next triangle number that is also pentagonal and hexagonal

#include <iostream>

#include "MathFunctions.h"

int main(){
  int i = 143;
  unsigned long result = 0;

  while(true){
    i++;
    result = i * (2 * i - 1);
    
    if(is_pentagonal(result))
      break;
  }
  
  std::cout << result << std::endl;
}
