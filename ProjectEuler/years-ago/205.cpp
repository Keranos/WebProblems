// What are the odds that rolling nine 4-sided die will have a higher
// value than six 6-sided die?

#include <iostream>
#include <iomanip>
#include <deque>
#include <math.h>
#include <stdlib.h>

#include "MathFunctions.h"

typedef std::deque<int> store;

store die_odds(const int& n, const int& s){
  store odds;

  int min = n;
  int max = n * s;

  for(int i = min; i <= max; ++i){
    int k_max = floor((i - n) / s);
    int term = 0;

    for(int j = 0; j <= k_max; ++j)
      term += pow(-1, j) * choose(n, j) * choose(i - s*j - 1, n - 1);
    odds.push_back(term);
  }

  return odds;
}


int main(){
  store peter = die_odds(9, 4);
  store colin = die_odds(6, 6);

  int diff = abs(peter.size() - colin.size());
  for(int i = 0; i < diff; ++i)
    peter.push_front(0);
  
  int n = peter.size();
  double result = 0;
  for(int i = 1; i < n; ++i)
    for(int j = 0; j < i; ++j)
      result += peter[i] * colin[j];
  double denom = pow(6, 6) * pow(4, 9);

  std::cout << std::setprecision(7) << result/denom << std::endl;
}
