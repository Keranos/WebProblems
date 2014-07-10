#include <iostream>

int main(){
  const int n = 100;
  int sum = n * (n + 1) / 2;
  int squared = n * (n + 1) * (2*n + 1) / 6;

  int result = sum * sum - squared;

  std::cout << result << std::endl;
}
