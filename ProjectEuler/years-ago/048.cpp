#include <iostream>

int main(){
  long result = 0;
  long modulo = 10000000000;

  for(int i = 1; i <= 1000; ++i){
    long sum = i;
    for(int j = 1; j < i; ++j){
      sum *= i;
      sum %= modulo;
    }   
    result += sum;
    result %= modulo;
  }

  std::cout << result << std::endl;
}
