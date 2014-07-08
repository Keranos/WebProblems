#include <iostream>
#include <string>
#include <algorithm>

int main(){
  std::string s;
  
  while(std::cin >> s && s != "#"){
    if(std::next_permutation(s.begin(),s.end()))
      std::cout << s << std::endl;
    else 
      std::cout << "No Successor" << std::endl;
  }
} 