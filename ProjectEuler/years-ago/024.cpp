#include <iostream> 
#include <algorithm>

int main(){
  int ints[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int count = 1;
  
  while(count < 1000000){
    std::next_permutation(ints, ints+10);
    ++count;
  }

  for(int i = 0; i < 10; ++i)
    std::cout << ints[i] << " ";
}
