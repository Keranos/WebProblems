// Find the value of d < 1000 for which 1/d contains the longest recurring
// cycle in its decimal fraction part

#include <iostream>
#include <vector>

#include "MathFunctions.h"

typedef std::vector<int> vec;

int main(){
  vec primes  = get_primes_below(1000);
  int length = 0;
  int result = 0;

  for(vec::reverse_iterator iter = primes.rbegin(); iter != primes.rend(); ++iter){
    if(length >= *iter) break;

    vec remainders(*iter);
    int position = 0;
    int value = 1;

    while(remainders[value] == 0 && value != 0){
      remainders[value] = position;
      value *= 10;
      value %= *iter;
      position++;
    }

    if(position - remainders[value] > length){
      length = position - remainders[value];
      result = *iter;
    }
  }
  
  std::cout << result << std::endl;
}
