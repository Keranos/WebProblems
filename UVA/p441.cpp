#include <iostream>
#include <vector>

int main(){
  int r, t;
  bool start = true;

  while(std::cin >> r && r != 0){
    if(!start)
      std::cout << std::endl;
    start = false;
    int count = 0;
    std::vector<int> S;
    while(count++ != r){
      std::cin >> t;
      S.push_back(t);
    }
    for(int i = 0; i != r-5; ++i)
      for(int j = i+1; j != r-4; ++j)
        for(int k = j+1; k != r-3; ++k)
          for(int l = k+1; l != r-2; ++l)
            for(int m = l+1; m != r-1; ++m)
              for(int n = m+1; n != r; ++n)
                std::cout << S[i] << " " << S[j] << " " << S[k] << " " << S[l] << " " << S[m] << " " << S[n] << std::endl;
    
  }
}