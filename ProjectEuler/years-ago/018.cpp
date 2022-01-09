#include <iostream>
#include <algorithm>
#include "Data.hpp"

int main(){
  for(int i = 13; i >= 0; --i)
    for(int j = 0; j <= i; ++j){
      int sum1 = Data::data18[i][j] + Data::data18[i+1][j];
      int sum2 = Data::data18[i][j] + Data::data18[i+1][j+1];
      Data::data18[i][j] = std::max(sum1, sum2);
    }

  std::cout << Data::data18[0][0] << std::endl;
}
