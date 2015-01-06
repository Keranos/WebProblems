// What is the first arrangement containing more than 10^12 discs where 
// the probability of pulling two blue discs (the rest are red) is 
// exactly 1/2?

#include <iostream>

int main(){
  unsigned long long b = 15;
  unsigned long long n = 21; 
  const unsigned long long max = 1000000000000;

  while(n < max){
    unsigned long long b1 = 3 * b + 2 * n - 2;
    unsigned long long n1 = 4 * b + 3 * n - 3;
    
    b = b1;
    n = n1;
  }

  std::cout << b << std::endl;
}
