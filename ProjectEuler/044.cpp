// Find the pair of pentagonal number, Pj and Pk, for which their sum 
// and difference are pentagonal and D = |Pj - Pk| is minimised.
// What is the value of D?     (Pn = n * (3*n - 1) / 2)

#include <iostream>
#include <cmath>

bool is_pentagonal(int n){
  double p = (sqrt(1 + 24 * n) + 1.0) / 6.0;
  return p == (int)p;
}

int main(){
  int result = 0; 
  bool solution_found = false;
  int i = 2;

  while(!solution_found){
    int m = i * (3*i - 1) / 2;
    
    for(int j = i - 1; j > 0; --j){
      int n = j * (3*j - 1) / 2;
      
      if(is_pentagonal(m+n) && is_pentagonal(m-n)){
	result = m - n;
	solution_found = true;
      }
    }
    i++;
  }

  std::cout << result << std::endl;
}
