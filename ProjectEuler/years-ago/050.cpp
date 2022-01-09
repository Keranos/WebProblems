// Which prime, below 1000000, can be written as the sum of the most 
// consecutive primes? 

#include <iostream> 
#include <vector>
#include <algorithm>

#include "MathFunctions.h"

typedef std::vector<int> vec;
typedef std::vector<int>::iterator vit;

int main(){
  const int limit = 1000000;
  vec primes = get_primes_below(limit);
  vec sums(primes.size() + 1);
  
  sums[0] = 0;
  for(int i = 1; i < primes.size(); ++i)
    sums[i] = sums[i-1] + primes[i - 1];
 
  int length = 1, result = 0;
  for(int i = length; i < sums.size(); ++i)
    for(int j = i - length - 1; j >= 0; --j){
      if(sums[i] - sums[j] > limit)
	break;
      
      vit it = std::find(primes.begin(), primes.end(), sums[i] - sums[j]);
      if(it != primes.end()){
	length = i - j;
	result = sums[i] - sums[j];
      }
    }

  std::cout << length << " " << result << std::endl;

}
