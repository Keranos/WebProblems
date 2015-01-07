// Find the smallest prime which, by replacing part of the number (not 
// necessarily adjacent digits) with the same digit, is part of an eight 
// prime value family.

#include <iostream>
#include <string> 
#include <sstream>
#include <algorithm>
#include <math.h>

#include "MathFunctions.h"

using namespace std;

string to_string(const int& n){
  ostringstream stm;
  stm << n;
  return stm.str();
}

int to_int(const string& s){
  stringstream ss(s);
  int result;
  return ss >> result ? result : 0;
}

bool three_same(string s, char c){
  return count(s.begin(), s.end(), c) == 3;
}

bool eight_prime(string s, char c){
  static const char n[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  
  int count = 0;
  for(int i = 0; i < 10; ++i){
    string t = s;
    replace(t.begin(), t.end(), c, n[i]);
    int a = to_int(t);
    
    if(i == 0 && *s.begin() == c)
      continue;

    if(is_prime(a)){
      count++;
    }
  }

  return count == 8;
}

int main(){
  int n = 10000;
  while(true){
    n = next_prime(n);
    string s = to_string(n);

    if((three_same(s, '0') && eight_prime(s, '0')) ||
       (three_same(s, '1') && eight_prime(s, '1')) || 
       (three_same(s, '2') && eight_prime(s, '2'))){
      cout << s << endl;
      break;
    }
  }
}
