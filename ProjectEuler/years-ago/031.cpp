// #31 - How many different ways can you make $2 in change with the 
// following coins { 1, 2, 5, 10, 20, 50, 100, 200 }

#include <iostream>

int main(){
  const int sum = 200;
  int coins[] { 1, 2, 5, 10, 20, 50, 100, 200 };
  int values[sum + 1] = {};
  values[0] = 1;

  for(int i = 0; i < 8; ++i)
    for(int j = coins[i]; j <= sum; ++j)
      values[j] += values[j - coins[i]];

  std::cout << values[sum] << std::endl;

}
