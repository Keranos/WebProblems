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
  int nPrimes = 1;
  int n = 1;

  while(nPrimes < 10001){
    n += 2;
    if(isPrime(n)) 
      nPrimes++;
  }

  std::cout << n << std::endl;
}
