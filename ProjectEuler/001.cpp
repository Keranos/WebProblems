#include <iostream>

int SmartSum(const int& n, const int& p){
  return n * (p/n) * ((p/n)+1)/2;
}

int main(){
  int result = SmartSum(3, 999) + SmartSum(5, 999) - SmartSum(15, 999);
  std::cout << result << std::endl;
}
