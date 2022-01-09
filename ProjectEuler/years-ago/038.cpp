// What is the largest 1 to 9 pandigital 9 digit that can be formed
// as teh concatenated product of an integer with (1, 2, ..., n) 
// where n > 1?

#include <iostream>

#include "MathFunctions.h"

int main(){
  for(int i = 9487; i >= 9234; --i){
    int num = concat(i, 2*i);
    if(is_pandigital(num)){
      std::cout << num << std::endl;
      break;
    }
  }
}
