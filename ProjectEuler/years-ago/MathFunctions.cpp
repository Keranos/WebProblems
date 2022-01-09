#include <math.h>
#include <vector>
#include <string>

#include "MathFunctions.h"

std::string convert_base(const unsigned int& n, const unsigned int& b){
  int t = n;
  std::string result;

  while(t > 0){
    result += t % b;
    t /= b;
  }

  return result;
}

unsigned long concat(const unsigned int& a, const unsigned int& b){
  unsigned long i = a, j = b;
  while(j > 0){
    i *= 10;
    j /= 10;
  }
  return i + b;
}

bool is_pandigital(long n){
  int digits = 0;
  int count = 0;
  int temp;
  
  while(n > 0){
    temp = digits;
    digits = digits | 1 << (int)((n % 10) - 1);
    if(temp == digits) return false;
    
    count++;
    n /= 10;
  }
  
  return digits == (1 << count) - 1;
}

bool is_palindrome(const unsigned long& n){
  unsigned long reversed = 0, orig = n;
  while (orig > 0){
    reversed = reversed * 10 + orig % 10;
    orig /= 10;
  }

  return n == reversed;
}

bool same_digits(const int& m, const int& n){
  int ints[10] = {};
  
  int temp = n;
  while(temp > 0){
    ints[temp % 10]++;
    temp /= 10;
  }
  
  temp = m;
  while(temp > 0){
    ints[temp % 10]--;
    temp /= 10;
  }

  for(int i = 0; i < 10; ++i)
    if(ints[i] != 0)
      return false;
  
  return true;
}

unsigned long series_sum(const unsigned long& n){
  return n * (n + 1) / 2;
}

std::vector<int> get_proper_factors(const int& n){
  std::vector<int> factors = get_factors(n);
  factors.pop_back();
  return factors;
}

std::vector<int> get_factors(const int& n){
  std::vector<int> factors;
  for(int i = 1; i <= (int)(n/2); ++i)
    if(n % i == 0)
      factors.push_back(i);
  factors.push_back(n);
  return factors;
}

bool is_pentagonal(const unsigned long& n){
  double p = (sqrt(1 + 24 * n) + 1.0) / 6.0;
  return p == (int)p;
}

int number_factors(const unsigned long& n){
  int count = 0;
  int square = sqrt(n);
  
  for(int i = 1; i <= square; ++i)
    if(n % i == 0)
      count += 2;

  if(square*square == n)
    count--;
  
  return count;
}

///////////////////////////////
// DISTRIBUTIONS
///////////////////////////////
unsigned long choose(unsigned int n, unsigned int k){
  if (k > n) return 0;
  if (k * 2 > n) k = n - k;
  if (k == 0) return 1;

  int result = n;
  for(int i = 2; i <= k; ++i){
    result *= (n - i + 1);
    result /= i;
  }
  return result;
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

unsigned long next_prime(const unsigned long& n){
  int i = n;
  while(true){
    if(is_prime(++i)) return i;
  }
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
