#include <iostream>

int main(){
  unsigned int target = 100;
  unsigned int ways[target + 1] = {};
  ways[0] = 1;

  for(int i = 1; i <= 99; i++)
    for(int j = i; j <= target; j++)
      ways[j] += ways[j - i];

  std::cout << ways[target] << std::endl;
}
