#include <iostream>
#include "Data.hpp"

int main(){
  int length = Data::data8.length();
  const int offset = 13;
  unsigned long result = 0;

  for(int i = 0; i < length - offset; ++i){
    unsigned long total = 1;
    for(int j = 0; j < offset; ++j)
      total *= (Data::data8.at(i + j) - '0');
    if(total > result) result = total;
  }

  std::cout << result << std::endl;
}
