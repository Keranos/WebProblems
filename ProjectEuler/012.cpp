#include <iostream>
#include <vector>
#include <algorithm>

#include "PrimeNumbers.h"

int series_sum(const int& n){
  return n * (n + 1) / 2;
}

int count_divisors(int n){
  if(n % 2 == 0) n = n/2;
  int divisors = 1;
  int count = 0;

  while(n % 2 == 0){
    count++;
    n /= 2;
  }
  
  divisors *= (count + 1);
  
  int p = 3;
  while(n != 1){
    count = 0;
    while(n % p == 0){
      count++;
      n /= p;
    }
    divisors *= (count + 1);
    p += 2;
  }
  
  return divisors;
}

int main(){
  int row = 1;
  int sum, result;

  int lnum = count_divisors(row);
  int rnum = count_divisors(row + 1);

  while(lnum * rnum / 2 < 501){
    row++;
    lnum = rnum;
    rnum = count_divisors(row + 1);
  }

  std::cout << series_sum(row) << std::endl;
}
