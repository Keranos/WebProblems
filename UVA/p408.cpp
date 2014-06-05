// 408 UniformGenerator
#include <vector>
#include <iostream>
#include <iomanip>

unsigned long int gcd(unsigned long int a, unsigned long int b){
  if(b == 0)
    return a;
  else 
    return gcd(b, a % b);
}

int main(){
  for(unsigned long int step, mod; std::cin >> step >> mod;){
    std::cout << std::setw(10) << step << std::setw(10) << mod << (gcd(step, mod) == 1 ? "    Good Choice" : "    Bad Choice") << std::endl << std::endl;;
  }
}