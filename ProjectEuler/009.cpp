#include <iostream>

int main(){
  for(int i = 1; i < 333; ++i)
    for(int j = i+1; j < 500; ++j)
      for(int k = j+1; k < 998; ++k)
	if(i*i + j*j == k*k && i + j + k == 1000){
	  std::cout << i*j*k << std::endl;
	  return 0;
	}
}
