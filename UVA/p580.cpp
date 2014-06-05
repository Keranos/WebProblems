#include <iostream>
#include <iomanip>
#include <math.h>

int main(){
  unsigned long int result;
  unsigned int n;

  while((std::cin >> n) && n != 0){
    if(n == 3)
      std::cout << 1 << std::endl;
    else
      std::cout << std::fixed << std::setprecision(0) << pow(2,n-2) + (n-2)*pow(2,n-3) << std::endl;
  }
}
