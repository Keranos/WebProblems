// Find the first four consecutive integers ot have four distinct 
// prime factors. What is the first of these numbers? 

#include <iostream> 
#include <vector>
#include <algorithm>

#include "MathFunctions.h"

typedef std::vector<int> vec;
typedef std::vector<int>::iterator vit;

vec unique_factors(const int& n){
  vec p = prime_factors(n);
  vit i = std::unique(p.begin(), p.end());
  p.resize(std::distance(p.begin(), i));
  return p;
}

int main(){
  bool allDistinct = false;
  int n = 210;
  int count = 1;

  int nDistinct = 4;
  
  while(count < nDistinct){
    n++;
    vec p = unique_factors(n);
    count = p.size() >= nDistinct ? count + 1 : 0;
  }

  std::cout << n - nDistinct + 1 << std::endl;
}
