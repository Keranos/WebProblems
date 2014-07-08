#include <iostream>
#include <vector>
#include <limits>

unsigned long long int fourMin(const unsigned long long int& a, const unsigned long long int& b, 
                               const unsigned long long int& c, const unsigned long long int& d){
  return std::min(std::min(std::min(a,b),c),d);
}

int main(){
  std::vector<unsigned long long int> a;
  a.push_back(1);

  int n = 0, p2 = 0, p3 = 0, p5 = 0, p7 = 0;

  while(a.size() != 5842){
    n++;
    a.push_back(fourMin(2*a[p2], 3*a[p3], 5*a[p5], 7*a[p7]));
    if(a[n] == 2*a[p2]) p2++;
    if(a[n] == 3*a[p3]) p3++;
    if(a[n] == 5*a[p5]) p5++;
    if(a[n] == 7*a[p7]) p7++;    
  }

  int m;
  while(std::cin >> m){ 
    std::cout << "The " << m;
    if(m % 100 > 9 && m % 100 < 21) std::cout << "th";
    else if(m % 10 == 1) std::cout << "st";
    else if(m % 10 == 2) std::cout << "nd";
    else if(m % 10 == 3) std::cout << "rd";
    else std::cout << "th";
    std::cout << " humble number is " << a[m-1] << "." << std::endl;
  }
}