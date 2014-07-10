#include <iostream>

int main(){
  unsigned long int total = 0;
  unsigned long int term1 = 1;
  unsigned long int term2 = 1;
  unsigned long int temp;

  while(term2 < 4000000){
    temp = term2;
    term2 += term1;
    term1 = temp;
    
    if(term2 % 2 == 0)
      total += term2;
  }

  std::cout << total << std::endl;
}
