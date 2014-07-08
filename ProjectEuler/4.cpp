#include <iostream>

bool IsPalidrome(int input)
{
  int r = 0;
  int n = input;

  for(; n != 0;){
    r *= 10;
    r += (n % 10);
    n /= 10;
  }

  return r == input ? true : false;
}

int main(){
  int result = 0;

  for(int i = 100; i < 1000; ++i)
    for(int j = 100; j < 1000; ++j){
      int temp = i * j;
      if(IsPalidrome(temp))
	if(result < temp)
	  result = temp;
    }

  std::cout << result << std::endl;
}
