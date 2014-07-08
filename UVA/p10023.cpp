#include <iostream>
#include <math.h>
#include <iomanip>

int main(){
  double n;
  while(std::cin >> n)
    std::cout << std::dec << sqrt(n) << std::endl;
}