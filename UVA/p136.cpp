// #136 Ugly Numbers 
#include <vector>
#include <iostream>
#include <limits>

int threeMin(const int& a, const int& b, const int& c){
  return std::min(std::min(a,b),c);
}

int main(){ 
  std::vector<int> a;
  a.push_back(1);

  int n=0, p2=0, p3=0, p5=0;

  while(a.size() != 1500){
    n++;
    a.push_back(threeMin(2*a[p2],3*a[p3],5*a[p5]));
    if(a[n] == 2*a[p2]) p2++;
    if(a[n] == 3*a[p3]) p3++;
    if(a[n] == 5*a[p5]) p5++;
  }

  std::cout << "The 1500'th ugly number is " << a[1499] << "." << std::endl;
}
