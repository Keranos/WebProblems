#ifndef __MATH_FUNCTIONS_H_
#define __MATH_FUNCTIONS_H_

#include <vector>
#include <string>
#include <iostream>

template<class T>
void display(const T& begin, const T& end){
  for(T i = begin; i != end; ++i)
    std::cout << *i << " ";
  std::cout << std::endl;
}


std::string convert_base(const unsigned int&, const unsigned int&);
unsigned long concat(const unsigned int&, const unsigned int&);

template<typename T>
T gcd(const T& a, const T& b){
  return b == 0 ? a : gcd<T>(b, a % b);
}

template<typename T>
T lcm(const T& a, const T& b){
  return (a * b) / gcd<T>(a, b);
}

bool is_palindrome(const unsigned long&);
bool is_pandigital(long);
bool same_digits(const int&, const int&);
unsigned long series_sum(const unsigned long&);
std::vector<int> get_proper_factors(const int&);
std::vector<int> get_factors(const int&);

bool is_pentagonal(const unsigned long&);
int number_factors(const unsigned long&);

unsigned long choose(unsigned int, unsigned int);

bool is_prime(const int&);
std::vector<int> get_primes_below(const int&);
std::vector<int> get_primes(const int&);
unsigned long next_prime(const unsigned long&);
std::vector<int> prime_factors(unsigned long long);

#endif
