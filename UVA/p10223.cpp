#include <iostream>
#include <vector>
#include <algorithm>

std::vector<unsigned long long> Catalan(){
  std::vector<unsigned long long> v;
  v.push_back(1);
  for(int i=1; i<20; ++i)
    v.push_back(v[i-1]*2*(2*i+1)/(i+2));
  return v;
}

int main(){
  std::vector<unsigned long long> storage = Catalan();
  std::vector<unsigned long long>::iterator iter;  

  int n;
  while(std::cin >> n){
    iter = std::find(storage.begin(), storage.end(), n);
    if(iter != storage.end())
      std::cout << iter - storage.begin() + 1 << std::endl;
  }
}