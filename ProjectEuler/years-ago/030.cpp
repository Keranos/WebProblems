// Find the sum of all the numbers that can be written as the sum of fifth 
// powers of their digits

#include <iostream>
#include <map>
#include <cmath>

int main(){
  std::map<int, int> powers; 
  for(int i = 0; i < 10; ++i)
    powers.insert( std::pair<int, int>(i, std::pow(i, 5.0)) );

  int result = 0;

  for(int i = 100; i < 295278; ++i){
    int t = i;
    int sum = 0;
    while(t != 0){
      int r = t % 10;
      sum += powers[r];
      t /= 10;
    }

    if(sum == i) result += i;
  }

  std::cout << result << std::endl;
}
