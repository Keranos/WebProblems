#include <iostream>

int main(){

  for(unsigned long long int num; std::cin >> num;){
    int count = 1, NUM = num;

    while(num > count){ num -= count; count++; }
    
    if(count % 2 == 0) std::cout << "TERM " << NUM << " IS " << num << "/" << count + 1 - num << std::endl;
    else std::cout << "TERM " << NUM << " IS " << count + 1 - num << "/" << num << std::endl;
  }
}