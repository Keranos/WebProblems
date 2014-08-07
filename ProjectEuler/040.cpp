// If d_n represents the nth digit of the Champernowne's constant, 
// find d1 * d10 * d100 * d1000 * d10000 * d100000 * d1000000

#include <iostream>
#include <cmath>
#include <string>

int get_nth_digit(int& n, int i){
  int t = n;
  while(n > i){
    t = n;
    n /= 10;
  }

  return t % 10;
}

int D(int n){
  int step = 1;
  int size = log10(step) + 1;
  while(n > size){
    n -= size;
    step++;
    size = log10(step) + 1;
  }
  
  return get_nth_digit(step, n-1);
}

int main(){
  int result = 1, mult = 1;
  for(int i = 0; i < 7; ++i){
    result *= D(mult);
    mult *= 10;
  }
  
  std::cout << result << std::endl;
}


