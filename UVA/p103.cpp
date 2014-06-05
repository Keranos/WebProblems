// 103 Stacking Boxes
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int> Veci;
typedef std::vector<std::pair<Veci, int> > Vecp;

bool Bigger(const Veci& v1, const Veci& v2){
  for(int i = 0; i != v1.size(); ++i)
    if(v1[i] <= v2[i])
      return false;
  return true;
}

int main(){
  Vecp storage, temp_sto(1);
  int n, d, count = 0;

  while(std::cin >> n >> d){
    int index = 1;
    while(n != count++){
      Veci temp(d);
      for(int i = 0; i != d; ++i)
        std::cin >> temp[i];
      
      std::sort(temp.begin(), temp.end());
      storage.push_back(std::make_pair(temp, index++) );
    }

    for(int i = 0; i != n-1; ++i)
      for(int j = i+1; j != n; ++j)
        if(Bigger(storage[i].first, storage[j].first)){
          temp_sto[0] = storage[i];
          storage[i] = storage[j];
          storage[j] = temp_sto[0];
        }
    
    Veci max_l(n,0);
    Veci P(n,0);
    int par, max, largest = 0, last;

    for(int i = 0; i != n; ++i){
      max = 0; par = -1;
      for(int j = i-1; j >= 0; --j)
        if(Bigger(storage[i].first, storage[j].first))
          if(max_l[j] > max){ max = max_l[j]; par = j; }
      P[i] = par;
      max_l[i] = max+1;
      if(max_l[i] > largest){
        largest = max_l[i];
        last = i;
      }
    }
  }
}