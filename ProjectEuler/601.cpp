#include <iostream>
#include "MathFunctions.h"

unsigned long long solve(unsigned long long limit, unsigned int streak){
  unsigned long long multiple = streak;
  for (unsigned long long i = 2; i < streak; i++)
    multiple = lcm<unsigned long long>(multiple, i);

  limit = limit - 2;
  auto atLeast = limit / multiple;

  multiple = lcm<unsigned long long>(multiple, streak + 1ULL);
  auto tooMany = limit / multiple;

  return atLeast - tooMany;
}

int main(){
  unsigned int limit = 31;
  unsigned long long result = 0;
  unsigned long long pow4 = 4;

  for (unsigned int i = 1; i <= limit; i++){
    result += solve(pow4, i);
    pow4 *= 4;
  }

  std::cout << result << std::endl;
}
