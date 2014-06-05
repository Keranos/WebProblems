#include <iostream>
#include <iomanip>
#include <math.h>

int main(){
  unsigned long long int sum, whereIam, lastHouse, numberHouses;

  for(whereIam = 6, lastHouse = 0, numberHouses = 0; numberHouses < 10; whereIam++){
    sum = 2*whereIam*whereIam;

    while(sum > lastHouse*(lastHouse+1))
      lastHouse++;

    if(sum == lastHouse*(lastHouse+1)){
      numberHouses++;
      std::cout << std::setw(10) << whereIam << std::setw(10) << lastHouse << std::endl;
    }
  }
}
