// #130 Roman Roulette
#include <iostream>
#include <list>
#include <iterator>

int main(){
  typedef std::list<int>::iterator l_iter;
  
  int n, k;
    
  while(std::cin >> n >> k && (n != 0 && k != 0)){
    std::list<int> x;
    bool start = true;

    for(int i = 1; i <= n; ++i)
      x.push_back(i);
  
    l_iter l_iter1, l_iter2;

    while(x.size() != 1){
      
      if(start) l_iter1 = x.begin();
  
      if(l_iter1 == x.end()) l_iter1 = x.begin();

      for(int i = 0 + start; i < k; ++i){
        start = false;
        l_iter1++;

        if(l_iter1 == x.end())
          l_iter1 = x.begin();
      }
      
      l_iter2 = l_iter1;      
  
      for(int j = 0; j < k; ++j){
        l_iter2++;

        if(l_iter2 == x.end())
          l_iter2 = x.begin();
      }          
      
      *l_iter1 = *l_iter2;
      if(l_iter1 == l_iter2) l_iter1 = x.erase(l_iter2);
      else x.erase(l_iter2);
    }
    std::cout << n - *x.begin() + 2 << std::endl;
  }
}