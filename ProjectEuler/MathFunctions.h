#ifndef __MATH_FUNCTIONS_H_
#define __MATH_FUNCTIONS_H_

#include <vector>

unsigned long gcd(const unsigned long&, const unsigned long&);
unsigned long lcm(const unsigned long&, const unsigned long&);

bool isPrime(const int&);
std::vector<int> getPrimes(const int&);
std::vector<int> primeFactors(unsigned long long);

#endif
