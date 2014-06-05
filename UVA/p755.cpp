// 755 - 487 - 3279
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <iterator>

using std::string;

string f(char c){
  string s(1,c);
  return s;
}

int main(){
  std::map<char, string> keypad;
  keypad['A'] = "2"; keypad['B'] = "2"; keypad['C'] = "2";
  keypad['D'] = "3"; keypad['E'] = "3"; keypad['F'] = "3";
  keypad['G'] = "4"; keypad['H'] = "4"; keypad['I'] = "4";
  keypad['J'] = "5"; keypad['K'] = "5"; keypad['L'] = "5";
  keypad['M'] = "6"; keypad['N'] = "6"; keypad['O'] = "6";
  keypad['P'] = "7"; keypad['R'] = "7"; keypad['S'] = "7";
  keypad['T'] = "8"; keypad['U'] = "8"; keypad['V'] = "8";
  keypad['W'] = "9"; keypad['X'] = "9"; keypad['Y'] = "9";

  int n, m, count_n = 0;
  std::cin >> n;

  std::map<string, unsigned short int> storage;
  std::map<string, unsigned short int>::iterator storage_iter;
  std::string number;
  number.reserve(20000);  
  std::map<char, string>::iterator siter;

  while(count_n != n){
    std::cin >> m;
    int count_m = 0; 

    while(count_m != m){
      std::cin >> number;
      std::string snumber;
      snumber.reserve(8);

      for(std::string::iterator iter = number.begin(); iter != number.end(); ++iter)
        if((*iter) != '-'){
          siter = keypad.find((*iter));
          snumber += siter == keypad.end() ? f(*iter) : siter->second;
          if(snumber.length() == 3)
            snumber += '-';
        }

      storage[snumber]++;
      count_m++;
    }

    bool depend = true;
    for(storage_iter = storage.begin(); storage_iter != storage.end(); ++ storage_iter){
      if(storage_iter->second != 1){
        std::cout << storage_iter->first << " " << storage_iter->second << std::endl;
        depend = false;
      }
    }

    if(depend)
      std::cout << "No duplicates." << std::endl;

    std::cout << std::endl;
    count_n++;
  }
}