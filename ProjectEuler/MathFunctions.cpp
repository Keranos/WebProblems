#include <iostream>
#include <math.h>
#include <vector>

#include "MathFunctions.h"

unsigned long gcd(const unsigned long& a, const unsigned long& b){
  return b == 0 ? a : gcd(b, a % b);
}

unsigned long lcm(const unsigned long& a, const unsigned long& b){
  return (a * b) / gcd(a, b);
}

unsigned long series_sum(const unsigned long& n){
  return n * (n + 1) / 2;
}

std::vector<int> get_factors(const int& n){
  std::vector<int> factors;
  for(int i = 1; i < n; ++i)
    if(n % i == 0)
      factors.push_back(i);
  return factors;
}

///////////////////////////////
// PRIME NUMBERS
///////////////////////////////
bool is_prime(const int& n){
  if(n <= 1) return false;
  int limit = (int)sqrt(n);
  for(int i = 2; i < limit+1; ++i)
    if(n % i == 0)
      return false;
  return true;
}

std::vector<int> get_primes_below(const int& n){
  std::vector<int> result;
  if(n < 1) return result;
  result.push_back(2);
  
  int i = 3; 
  while(i <= n){
    if(is_prime(i))
      result.push_back(i);
    i += 2;
  }

  return result;
}

std::vector<int> get_primes(const int& n){
  std::vector<int> result;
  if(n < 1) return result;
  result.push_back(2);

  int i = 3;
  while(result.size() < n){
    if(is_prime(i))
      result.push_back(i);
    i += 2;
  }

  return result;
}

std::vector<int> prime_factors(unsigned long long n){
  unsigned long long limit = (unsigned long long)n/2 + 1;
  std::vector<int> result;

  for(unsigned int i = 2; i <= limit; ++i){
    if(n == 1) continue;
    while(n % i == 0){
      n /= i;
      result.push_back(i);
    }
  }

  return result;
}
