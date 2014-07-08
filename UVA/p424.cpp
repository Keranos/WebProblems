#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

using std::string;
using std::cout;
using std::cin;

class BadConversion : public std::runtime_error {
  public :
    BadConversion(const string& s) : std::runtime_error(s) { }
};

inline int convertToInt(const char& c){
  string s(1,c);
  std::istringstream i(s);
  int x;
  if(!(i >> x))
    throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}

int main(){
  const int n = 105;
  int hold[100][n] = {0};
  int sol[n] = {0};
  string s;
  s.reserve(100);
  int num = 0;  

  while(cin >> s && s != "0"){
    for(int i = 0; i != s.length(); ++i)
      hold[num][n-i-1] = convertToInt(s[s.length()-i-1]);
    num++;
  }

  int rem = 0, sum;

  for(int i = n-1; i != -1; --i){
    sum = rem;
    rem = 0;
    for(int j = 0; j != num; ++j)
      sum += hold[j][i];
    if(sum > 9)
      rem = sum/10;
    sol[i] = sum % 10;
  }

  bool start = false;
  for(int i = 0; i != n; ++i){
    if(sol[i] != 0)
      start = true;
    if(start)
      std::cout << sol[i];
  }
  std::cout << std::endl;
}