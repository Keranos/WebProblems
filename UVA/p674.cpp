// This version solves 357 and 147 also.

#include <iostream>
#include <map>
#include <iomanip>

const int max = 30000;
int coin[5] = {50, 25, 10, 5, 1};

int main(){ 
  std::map<int, unsigned long long int> change;
  
  change[0]++;
  int c;
  for(int i = 0; i < 5; ++i){
    c = coin[i];
    for(int j = c; j <= max; ++j)
      change[j] += change[j-c];
  }

  int n;
  for(; std::cin >> n;)
    if(change[n] > 1)
      std::cout << "There are " << change[n] << " ways to produce " << n << " cents change." << std::endl;
    else 
      std::cout << "There is only 1 way to produce " << n << " cents change." << std::endl;
}