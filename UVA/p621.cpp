#include <iostream>
#include <string>

int main(){
  int input;
  std::string s;  

  std::cin >> input;
  while(input--){
    std::cin >> s;
    if(s.compare("1") == 0 || s.compare("4") == 0 || s.compare("78") == 0)
      std::cout << "+" << std::endl;
    else if(s.size() > 1){
      if(s[s.size()-2] == '3' && s[s.size()-1] == '5')
        std::cout << "-" << std::endl;
      else if(s[0] == '9' && s[s.size()-1] == '4')
        std::cout << "*" << std::endl;
      else if(s.size() > 2)
        if(s[0] == '1' && s[1] == '9' && s[2] == '0')
          std::cout << "?" << std::endl;
    }
  }
}