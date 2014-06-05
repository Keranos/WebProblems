// 144 Student Grant 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator>

int main(){
  std::vector<int>::iterator w_iter, s_iter;

  int N, k;
  while(std::cin >> N >> k && (N != 0 && k != 0)){
    std::vector<int> students(N, 0);
    std::vector<int> who;
    for(int i = 0; i < N; ++i) who.push_back(i+1);    

    int track = 1;
    int amount = 1;
    int leftover = 0;
    int hold = 0;

    w_iter = who.begin(); 
    s_iter = students.begin();

    while(students.size() != 0){
      *s_iter += amount;

      if(*s_iter >= 40){
        std::cout << std::setw(3) << *w_iter;
        leftover = *s_iter%40;
        s_iter = students.erase(s_iter);
        w_iter = who.erase(w_iter);
      }
      else{
        leftover = 0;
        s_iter++; w_iter++;
      }    

      if(s_iter == students.end()) { s_iter = students.begin(); w_iter = who.begin(); }   

      if(leftover > 0){ amount = leftover; leftover = 0;}
      else if(hold > 0){ amount = track; hold = 0;}
      else{ track++; if(track > k) track = 1; amount = track; }
    }
    std::cout << std::endl;
  }
}
