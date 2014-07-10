#include <iostream>
#include <math.h>

int main(){
  int divisors = 0;
  unsigned long int n = 1;
  unsigned long total;

  while(divisors < 500){
    divisors = 0;
    n++;
    total = n * (n + 1) / 2;
    unsigned long int m = int (floor(sqrt(total)));

    for(unsigned long int i = 1; i <= m; ++i)
      if(total % i == 0)
	divisors += (i * i) == total ? 1 : 2;
  }

  std::cout << total << " " << divisors << std::endl;
}
