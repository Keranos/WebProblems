// 150 + 440
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

int main(){
  typedef std::list<int>::iterator l_iter;

  int x;

  while(std::cin >> x && x != 0 && x > 2){
    std::list<int> ll, l;
    for(int i = 1; i <= x; ++i)
      ll.push_back(i);

    bool solved = false;
    int count = 0;

    while(!solved){
      l = ll;
      count++;
      
      l_iter iter = l.begin();
      iter = l.erase(iter);
      
      while(true){
        for(int i = 1; i < count; ++i){
          iter++; 
          if(iter == l.end())
            iter = l.begin(); 
        }

        iter = l.erase(iter);
        if(iter == l.end()) iter = l.begin();

        l_iter temp = std::find(l.begin(),l.end(), 2);
        
        if(temp == l.end()) break;
        if(l.size() == 1){
          solved = true;
          break;
        }
      }
    }
    std::cout << count << std::endl;
  }
}