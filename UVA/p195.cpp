#include <iostream>
#include <algorithm>
#include <string>
#include <functional>

int main(){
  int input;
  std::string s;

  std::cin >> input; 
  for(int i = 0; i != input; ++i){
    std::cin >> s;
    std::sort(s.begin(), s.end());
    std::cout << s << std::endl;
    while(std::next_permutation(s.begin(), s.end()))
      std::cout << s << std::endl;
  }
}