#include <iostream>
#include <string>

int main(){
  unsigned long int n1, n2;
  int rem = 0, carry = 0, sum;

  while(std::cin >> n1 >> n2 && (n1 != 0 && n2 != 0)){
    carry = 0; rem = 0; sum = 0;
    while((n1 > 0) || (n2 > 0)){
      sum = rem + (n1 % 10) + (n2 % 10);
      
      if(sum > 9) carry++;
      
      rem = sum/10;
      n1 /= 10;
      n2 /= 10;
    }

    if(carry == 0)
      std::cout << "No carry operation." << std::endl;
    else if(carry == 1)
      std::cout << "1 carry operation." << std::endl;
    else 
      std::cout << carry << " carry operations." << std::endl;
  }

  return 0;
}