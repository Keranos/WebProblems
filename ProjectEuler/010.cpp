#include <iostream>

bool isPrime(const int& n){
  if (n <= 1) return false;
  if (n == 2) return true;
  if (n % 2 == 0) return false;

  int c = 3;
  
  while(c * c <= n){
    if (n % c == 0) return false;
    c += 2;
  }

  return true;
}

int main(){
  unsigned long int total = 2;
  unsigned long int n = 1;

  while(n < 2000000){
    n += 2;
    if(isPrime(n)) 
      total += n;
  }

  std::cout << total << std::endl;
}
