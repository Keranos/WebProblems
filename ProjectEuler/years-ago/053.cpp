// How many, not necessarily distinct, value of C^n_r, for 1 <= n <= 100,
// are greater than one-million?

#include <iostream>

bool choose(unsigned int n, unsigned int k){
  const int m = 1000000;
  
  if (k > n) return false;
  if (k * 2 > n) k = n - k;
  if (k == 0) return (n > m) ? true : false;

  int r = n;
  for(int i = 2; i <= k; ++i){
    r *= (n - i + 1);
    r /= i;
    if (r > m) 
      return true;
  }

  return false;
}

int main(){
  const int max = 100;
  int count = 0;
  for(int n = 1; n <= max; ++n)
    for(int r = 1; r <= n; ++r)
      if(choose(n, r))
	count++;
  std::cout << count << std::endl;
}
