#include <iostream>

int main(){ 
  unsigned long long n;
  while(std::cin >> n)
    std::cout << n*n*(n+1)*(n+1)/4 << std::endl;
}