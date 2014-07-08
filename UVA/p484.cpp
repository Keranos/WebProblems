#include <map>
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

int main(){
  int t;
  std::vector<int> vi;
  std::vector<int>::iterator iter;
  std::map<int, int> mii;

  while(std::cin >> t){
    if(std::find(vi.begin(), vi.end(), t) == vi.end())
      vi.push_back(t);
    mii[t]++;
  }

  for(iter = vi.begin(); iter != vi.end(); ++iter)
    std::cout << *iter << " " << mii[*iter] << std::endl;
}