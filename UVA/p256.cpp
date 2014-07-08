#include <iostream>
#include <map>
#include <iomanip>
#include <iterator>
#include <algorithm>

int main(){
  std::multimap<int, int> mm;

  for(int i=0; i<10; ++i)
    for(int j=0; j<10; ++j){
      if((j+i)*(j+i) == (10*i + j))
        mm.insert(std::pair<int,int>(2, (10*i + j)));
      for(int k=0; k<10; ++k)
        for(int l=0; l<10; ++l){
          if(((i+k)*10 + j+l)*((i+k)*10 + j+l) == (1000*i + 100*j + 10*k + l))
            mm.insert(std::pair<int,int>(4, (1000*i + 100*j + 10*k + l)));
          for(int m=0; m<10; ++m)
            for(int n=0; n<10; ++n){
              if(((i+l)*100 + (j+m)*10 + k+n)*((i+l)*100 + (j+m)*10 + k+n) == (100000*i + 10000*j+ 1000*k + 100*l + 10*m + n))
                mm.insert(std::pair<int,int>(6, (100000*i + 10000*j+ 1000*k + 100*l + 10*m + n)));
              for(int p=0; p<10; ++p)
                for(int q=0; q<10; ++q){
                  if(((i+m)*1000 + (j+n)*100 + (k+p)*10 + l+q)*((i+m)*1000 + (j+n)*100 + (k+p)*10 + l+q) == (10000000*i + 1000000*j + 100000*k + 10000*l + 1000*m + 100*n + 10*p + q))
                    mm.insert(std::pair<int,int>(8, (10000000*i + 1000000*j + 100000*k + 10000*l + 1000*m + 100*n + 10*p + q)));
                }
            }
        }
    }

  int n;
  std::pair<std::multimap<int, int>::iterator, std::multimap<int, int>::iterator> pii;

  while(std::cin >> n){
    pii = mm.equal_range(n);
    for(std::multimap<int, int>::iterator iter = pii.first; iter != pii.second; ++iter)
      std::cout << std::setfill('0') << std::setw(n) << iter->second << std::endl;
  }
        
}
