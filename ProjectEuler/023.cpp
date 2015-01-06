#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "MathFunctions.h"

// Sum of all positive integers which cannot be written as the 
// sum of two abundant numbers.

const int limit = 28123;

int sum_factors(const std::vector<int>& v){
  return std::accumulate(v.begin(), v.end(), 0);
}

std::vector<int> get_abundant_numbers(){
  std::vector<int> result;
  
  for(int i = 1; i < limit; ++i)
    if(i < sum_factors(get_proper_factors(i)))
      result.push_back(i);
  
  return result;
}

std::vector<bool> sum_of_abundant_numbers(std::vector<int>& v){
  std::vector<bool> result(limit, false);
  
  for(int i = 0; i < v.size(); ++i)
    for(int j = i; j < v.size(); ++j){
      if(v[i] + v[j] >= limit) 
	break;
      result[v[i] + v[j]] = true;
    }

  return result;
}

int main(){
  std::vector<int> abundant_numbers = get_abundant_numbers();
  std::vector<bool> sum_of_abundants = sum_of_abundant_numbers(abundant_numbers);

  unsigned long total = 0;
  for(int i = 0; i < sum_of_abundants.size(); ++i)
    if(!sum_of_abundants[i]){ 
      total += i;
    }

  std::cout << total << std::endl;
}
