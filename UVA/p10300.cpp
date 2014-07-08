#include <iostream>

int main(){
  int n, f;
  unsigned long long a, b, c;
  std::cin >> n;
  while(n--){
    std::cin >> f;
    unsigned long long result = 0;
    while(f--){
      std::cin >> a >> b >> c;
      result += a*c;
    }
    std::cout << result << std::endl;
  }
}