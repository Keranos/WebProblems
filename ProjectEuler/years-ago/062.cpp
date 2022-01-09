// Find the smallest cube for which exactly five permutations of its 
// digits are cube

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

#include "MathFunctions.h"

struct Point{
  int value;
  int count;
};

unsigned long long modify_number(const unsigned long long n){
  long k = n*n*n;
  int digits[10] = { }; 
  unsigned long long sol = 0;
  
  while(k > 0){
    digits[k % 10]++;
    k /= 10;
  }
  
  for(int i = 9; i >= 0; --i)
    for(int j = 0; j < digits[i]; ++j)
      sol = sol*10 + i;
  
  return sol;
}

int main(){
  std::map<int, Point> cubes;
  unsigned long long n = 345;
  
  while(true){
    n++;
    unsigned long long p = modify_number(n);
    if(cubes.find(p) == cubes.end()){
      Point pp = {n, 1};
      cubes[p] = pp;
    }

    if((cubes[p].count++) == 5){
      std::cout << cubes[p].value << std::endl;
      break;
    }
  }
}
