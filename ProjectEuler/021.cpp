#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

#include "MathFunctions.h"

// Find the sum of all amicable number under 10000

typedef std::unordered_map<int, int> map;

int sum_factors(const std::vector<int>& factors){
  return std::accumulate(factors.begin(), factors.end(), 0);
}

int main(){
  int result = 0;
  map storage;
  
  for(int i = 3; i < 10000; ++i){
    map::const_iterator iter = storage.find(i);
    int a1 = iter == storage.end() ? sum_factors(get_factors(i)) : iter->second;
     if(iter == storage.end())
      storage.insert( {i, a1} );

    iter = storage.find(a1);
    int a2 = iter == storage.end() ? sum_factors(get_factors(a1)) : iter->second;
    if(iter == storage.end())
      storage.insert( {a1, a2} );

    if(a2 == i && a1 != a2){
      result += a1;
    }
  }

  std::cout << result << std::endl;
}
