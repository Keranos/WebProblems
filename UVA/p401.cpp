// #401 - Palindromes
#include <iostream>
#include <map>
#include <string>
#include <iterator>

int main(){

  std::map<char, char> mirror;
  mirror['A'] = 'A'; mirror['E'] = '3'; mirror['H'] = 'H';
  mirror['I'] = 'I'; mirror['J'] = 'L'; mirror['J'] = 'L';
  mirror['L'] = 'J'; mirror['M'] = 'M'; mirror['O'] = 'O';
  mirror['S'] = '2'; mirror['T'] = 'T'; mirror['U'] = 'U';
  mirror['V'] = 'V'; mirror['W'] = 'W'; mirror['X'] = 'X';
  mirror['Y'] = 'Y'; mirror['Z'] = '5'; mirror['1'] = '1';
  mirror['2'] = 'S'; mirror['3'] = 'E'; mirror['5'] = 'Z';
  mirror['8'] = '8';

  for(std::string word; std::cin >> word;){
    bool isPal = true, isMir = true;

    std::string::iterator forward;
    std::string::reverse_iterator reverse;

    for(forward = word.begin(), reverse = word.rbegin(); 
        (isPal || isMir) && forward != word.end();
        ++forward, ++reverse){
      if(isPal && *forward != *reverse)
        isPal = false;
      if(isMir && mirror[(char)(*forward)] != *reverse)
        isMir = false;
    }
    
    std::cout << word << " -- is ";
    
    if(isPal && isMir) std::cout << "a mirrored palindrome.";
    else if (isMir) std::cout << "a mirrored string.";
    else if (isPal) std::cout << "a regular palindrome.";
    else std::cout << "not a palindrome.";

    std::cout << std::endl << std::endl;

  }
}