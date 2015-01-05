#ifndef __MATH_FUNCTIONS_H_
#define __MATH_FUNCTIONS_H_

#include <vector>
#include <string>

std::string convert_base(const unsigned int&, const unsigned int&);
unsigned long concat(const unsigned int&, const unsigned int&);

unsigned long gcd(const unsigned long&, const unsigned long&);
unsigned long lcm(const unsigned long&, const unsigned long&);
bool is_palindrome(const unsigned long&);
bool is_pandigital(long);
bool same_digits(const int&, const int&);
unsigned long series_sum(const unsigned long&);
std::vector<int> get_factors(const int&);

bool is_pentagonal(const unsigned long&);
int number_factors(const unsigned long&);

bool is_prime(const int&);
std::vector<int> get_primes_below(const int&);
std::vector<int> get_primes(const int&);
unsigned long next_prime(const unsigned long&);
std::vector<int> prime_factors(unsigned long long);

#endif
