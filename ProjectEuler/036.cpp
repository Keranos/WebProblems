// Find the sum of all numbers, less than one million, which are 
// palidromic in base 10 and base 2.

#include <iostream>
#include <string>
#include <algorithm>

#include "MathFunctions.h"

int main(){
  int result = 0;

  for(int i = 1; i < 1000000; ++i)
    if(is_palindrome(i)){
      std::string b = convert_base(i, 2);
      if( std::equal(b.begin(), b.begin() + b.size()/2, b.rbegin()))
	result += i;
    }

  std::cout << result << std::endl;
}
