// 948 Fibonaccimal Base 

#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <stdexcept>
#include <sstream>

class BadConversion : public std::runtime_error { 
  public:
  BadConversion(const std::string& s) : std::runtime_error(s) { }
};

inline std::string stringify(const int& x){
  std::ostringstream o;
  if(!(o << x))
    throw BadConversion("stringify");
  return o.str();
}

int main(){
  std::vector<unsigned long int> Fib;
  Fib.push_back(1); Fib.push_back(2);
  while(*Fib.rbegin() < 100000000)
    Fib.push_back(*Fib.rbegin() + *(++Fib.rbegin()));

  unsigned long int input;
  std::vector<unsigned long int>::reverse_iterator siter;
  int num;
  int n;
  std::cin >> n;
  while(n-- != 0){
    std::cin >> input;
    std::string s;
    int input1 = input;
    bool start = false;
    for(siter = Fib.rbegin(); siter != Fib.rend(); ++siter){
      num = input / *siter;
      if(num > 0){ s += stringify(num); start = true; input -= num*(*siter); }
      else if(start) s += stringify(0);
    } 

    std::cout << input1 << " = " << s << " (fib)" << std::endl;
  }

}