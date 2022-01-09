#include <iostream>

#include "MathFunctions.h"

int main(){
  int total = 1;
  
  for(int i = 2; i <= 20; ++i)
    total = lcm(total, i);
  
  std::cout << total << std::endl;
}
