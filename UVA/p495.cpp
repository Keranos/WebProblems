// #495 FibonacciFreeze

#include <vector>
#include <iostream>

std::vector<unsigned long int> fibber(){
  std::vector<unsigned long int> fib(5001);
  fib[0] = 0;
  fib[1] = 1;

  for(int i = 2; i != 5001; ++i)
    fib[i] = fib[i-1] + fib[i-2];

  return fib;
}

int main(){
  std::vector<unsigned long int> fib = fibber();

  for(int n; std::cin >> n;)
    std::cout << "The Fibonacci number for " << n << " is " << fib[n] << std::endl;
}