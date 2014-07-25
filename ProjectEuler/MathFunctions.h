#ifndef __MATH_FUNCTIONS_H_
#define __MATH_FUNCTIONS_H_

#include <vector>

unsigned long gcd(const unsigned long&, const unsigned long&);
unsigned long lcm(const unsigned long&, const unsigned long&);
unsigned long series_sum(const unsigned long&);
std::vector<int> get_factors(const int&);

bool is_prime(const int&);
std::vector<int> get_primes_below(const int&);
std::vector<int> get_primes(const int&);
std::vector<int> prime_factors(unsigned long long);

#endif
