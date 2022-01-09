#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "MathFunctions.h"

int main(){
  int row = 0;
  int i = 1;

  while(number_factors(row) < 500){
    row += i;
    i++;
  }
    
  std::cout << row << std::endl;
}
