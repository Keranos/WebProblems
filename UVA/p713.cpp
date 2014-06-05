// #713 Adding Reversed Numbers
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <stdexcept>
#include <algorithm>
#include <functional>

using std::string;
using std::cout;
using std::cin;

 class BadConversion : public std::runtime_error {
 public:
   BadConversion(const std::string& s)
     : std::runtime_error(s)
     { }
 };

inline int convertToInt(const char& c){
  string s(1,c); 
  std::istringstream i(s);
  int x;
  if (!(i >> x))
    throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}

inline string stringify(const int& x){
  std::ostringstream o;
  if(!(o << x))
    throw BadConversion("stringify");
  return o.str();
}

inline string addition(const char& c1, const char& c2, int& rem){
  int add = convertToInt(c1) + convertToInt(c2) + rem;
  rem = add / 10;
  add -= rem*10;
  return stringify(add);
}

int main(){
  for(string N1, N2; cin >> N1 >> N2;){
    string solution, temp;
    string::iterator N1_iter, N2_iter, t1;
    int rem = 0;
    bool longer = N1.length() > N2.length() ? true : false;
    for(N1_iter = N1.begin(), N2_iter = N2.begin(); !longer ? N1_iter != N1.end() : N2_iter != N2.end();
        ++N1_iter, ++N2_iter){
      temp = addition(*N1_iter, *N2_iter, rem);
      solution += temp;
    }

    for(;longer ? N1_iter != N1.end() : N2_iter != N2.end(); longer ? ++N1_iter : ++N2_iter){
      string zero = "0";
      if(longer)
        temp = addition(*N1_iter, *zero.begin(), rem);
      else
        temp = addition(*N2_iter, *zero.begin(), rem);
      rem = 0;
      solution += temp;
    }

    if(N1.length() == N2.length()) 
      solution += stringify(rem);
  
    t1 = std::find_if(solution.begin(), solution.end(), std::bind2nd(std::not_equal_to<char>(),'0'));
    solution.erase(solution.begin(), t1);
    std::cout << solution << std::endl;
  }
}