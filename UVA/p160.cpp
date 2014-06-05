// 160 Factors 
#include <iostream>
#include <map>
#include <vector>
#include <iterator>
#include <iomanip>

int main(){
  int n;
  int num[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

  std::map<int, int> emptymap;

  std::vector<std::map<int,int> > list;

  list.push_back(emptymap);

  for(int i = 2; i != 101; ++i){
    //list.push_back(emptymap);
    int trial = i;
    int j = 0;
    while(trial != 1){
      if(trial % num[j] == 0){
        list[i-2][num[j]]++;
        trial = trial/num[j];
        j=0;
      }
      else j++;
    }
    list.push_back(list[i-2]);
  }

  while(std::cin >> n && n != 0){
    std::cout << std::setw(3) << n << "! =";

    std::map<int, int>::iterator iter;
    for(iter = list[n-2].begin(); iter != list[n-2].end(); ++iter){
      std::cout << std::setw(3) << iter->second;
    }
    std::cout << std::endl;
  }
}
