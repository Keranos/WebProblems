#include <iostream>

int main(){
  unsigned long fn0 = 1, fe0 = 1, fw0 = 1, fs0 = 1, fn, fe, fw, fs;
  unsigned long result = 1;

  for(int i = 0; i < 500; ++i){
    fn = fn0 + (2 + (i*8));
    fn0 = fn;
    
    fe = fe0 + (4 + (i*8));
    fe0 = fe;
    
    fw = fw0 + (6 + (i*8));
    fw0 = fw;
    
    fs = fs0 + (8 + (i*8));
    fs0 = fs;
    
    result += (fn + fe + fw + fs);
  }

  std::cout << result << std::endl;
}
