#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

inline void move_and_push(std::string & s, const unsigned long long & del, const int & in){
  std::string ss(1, s[del]);
  s.erase(del,1);
  s.insert(in, ss);
}

inline std::vector<unsigned long long> factorial(const int & a){
  std::vector<unsigned long long> fact(1,1);
  for(int i = 1; i != a-1; ++i)
    fact.push_back(fact[i-1]*(i+1));
  return fact;
}

int main(){
  std::string ttt = "aabcc";
  while(next_permutation(ttt.begin(), ttt.end()) != false)
    std::cout << ttt << std::endl;


  std::vector<unsigned long long> fact = factorial(20);

  unsigned long long n;
  std::cin >> n;
  
  std::string s;
  unsigned long long num;

  unsigned long long div;

  while(n--){
    std::cin >> s >> num;
    if(num != 0){   
      int size_s = s.size();
  
      std::sort(s.begin(), s.end());
    
      for(int i = 0; i != s.size() - 1; ++i){
        div = num/fact[s.size() - i - 2];
        if(div != 0){
          move_and_push(s, div + i, i);
          num -= div*fact[s.size() - i - 2];
        }
      }
    }
    std::cout << s << std::endl;
  }

  exit(0);
}