#include <iostream>
#include <iomanip>
#include <math.h>

int main(){
  unsigned long int sum1, sum2, sum3, whereIam(6), lastHouse;
  int numberHouses(0);

  while(numberHouses != 10){
    sum1 = (whereIam*(whereIam-1))/2;
    lastHouse = static_cast<int>(-0.5 + 0.5*sqrt(1 + 8*whereIam*whereIam)); 
    sum3 = (whereIam*(whereIam+1))/2;
    sum2 = lastHouse*(lastHouse+1)/2 - sum3;
    while(sum1 > sum2){
      lastHouse++;
      sum2 = lastHouse*(lastHouse+1)/2 - sum3;
    }
    
    if(sum1 == sum2){
      numberHouses++;
      std::cout << std::setw(10) << whereIam << std::setw(10) << lastHouse << std::endl;
    }
    whereIam++;
  }
}
