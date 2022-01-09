#include <iostream>
#include <vector>
#include <algorithm>

#include "Data.hpp"

const int s11 = 20;

unsigned long horizontal(const int d[], const int& i, const int& j){
  if(j > 16) return 0;
  return d[i*s11 + j] * d[i*s11 + j + 1] * d[i*s11 + j + 2] * d[i*s11 + j + 3];
}

unsigned long vertical(const int d[], const int& i, const int& j){
  if(i > 16) return 0;
  return d[i*s11 + j] * d[(i+1)*s11 + j] * d[(i+2)*s11 + j] * d[(i+3)*s11 + j];
}

unsigned long slantedForward(const int d[], const int& i, const int& j){
  if(j > 16 || i < 3) return 0;
  return d[i*s11 + j] * d[(i-1)*s11 + j + 1] * d[(i-2)*s11 + j + 2] * d[(i-3)*s11 + j + 3];
}

unsigned long slantedBackward(const int d[], const int& i, const int& j){
  if(j > 16 || i > 16) return 0;
  return d[i*s11 + j] * d[(i+1)*s11 + j + 1] * d[(i+2)*s11 + j + 2] * d[(i+3)*s11 + j + 3];
}

unsigned long maxProblem11(const int d[], const int& i, const int& j){
  return std::max(horizontal(d, i, j), std::max(vertical(d, i, j), std::max(slantedForward(d, i, j), slantedBackward(d, i, j))));
}

int main(){
  int total_11 = 0;
  for(int i = 0; i < s11; ++i)
    for(int j = 0; j < s11; ++j){
      int temp = maxProblem11(Data::data11, i, j);
      if(temp > total_11) total_11 = temp;
    }
  
  std::cout << total_11 << std::endl;  
}
