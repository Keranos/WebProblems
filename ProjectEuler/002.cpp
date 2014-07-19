#include <iostream>

int main(){
  long fib3 = 3;
  long fib6 = 0;
  long result = 2;
  long summed = 0;

  while(result < 4000000){
    summed += result;
    
    result = 4*fib3 + fib6;
    fib6 = fib3;
    fib3 = result;
  }

  std::cout << result << std::endl;
}
