// 834 - Continued Fractions
#include <iostream>
#include <vector>

//void output(std::list<unsigned long int> cf){
//  for(int 
//}

unsigned long int gcd(unsigned long int a, unsigned long int b){
  unsigned long int t;
  while(b != 0){
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void output(std::vector<unsigned long int> l){
  std::cout << "[";
  for(int i = 0; i < l.size(); ++i){
    if(i == 1) std::cout << ";";
    else if(i > 1) std::cout << ",";
    std::cout << l[i];
  }
  std::cout << "]" << std::endl;
}

int main(){
  unsigned long int r = 0, div;
  std::vector<unsigned long int> cf;
  unsigned long int g;
  
  for(unsigned long int n, d; std::cin >> n >> d;){
    g = gcd(n, d);
    n /= g;
    d /= g;
    while(r != 1){
      div = n / d;
      cf.push_back(div);
      r = n % d;
      if(r == 1){ cf.push_back(d); break; }
      g = gcd(n, d);
      n = d / g;
      d = r / g;
    }
    output(cf);
    cf.clear();
    r = 0;
  }
}