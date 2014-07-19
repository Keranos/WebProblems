#include <iostream> 

const int s = 21;

int main(){
  unsigned long long grid[s][s];
 
  // Initialize
  for(int i = 0; i < s; ++i){
    grid[i][0] = 1;
    grid[0][i] = 1;
  }

  for(int i = 1; i < s; ++i)
    for(int j = 1; j < s; ++j)
      grid[i][j] = grid[i-1][j] + grid[i][j-1];

  std::cout << grid[s-1][s-1] << std::endl;
}
