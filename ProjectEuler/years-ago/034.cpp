#include <iostream> 
#include <map>

std::map<int, int> factorial = { {0, 1}, {1, 1}, {2, 2}, {3, 6}, {4, 24}, {5, 120}, {6, 720}, {7, 5040}, {8, 40320}, {9, 362880} };

int main(){
  int result = 0;
  
  for(int i = 3; i < 2540160; ++i){
    int sum = 0;
    int t = i;
    
    while(t != 0){
      int r = t % 10;
      sum += factorial[r];
      t /= 10;
    }

    if(sum == i) result += i;
  }

  std::cout << result << std::endl;
}
