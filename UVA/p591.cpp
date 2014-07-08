#include <iostream>
#include <vector>
#include <numeric>

int main(){
  int num, set = 0;
  while(std::cin >> num && num != 0){
    set++;
    std::vector<int> vi(100);
    for(int i = 0; i != num; ++i)
      std::cin >> vi[i];
    
    int height = std::accumulate(vi.begin(), vi.end(),0)/num;
    int move = 0;
    for(int i = 0; i != num; ++i)
      if(vi[i] > height)
        move += vi[i] - height;

    std::cout << "Set #" << set << std::endl;
    std::cout << "The minimum number of moves is " << move << "." << std::endl;
    std::cout << std::endl;
  }
}