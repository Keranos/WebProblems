#include <iostream>
#include <unordered_map>

typedef unsigned long long ull;
std::unordered_map<ull, ull> storage;

ull getCollatz(const ull& i){
  std::unordered_map<ull, ull>::const_iterator iter = storage.find(i);
  if(iter != storage.end()) return iter->second;
  else{
    if(i % 2 == 0)
      storage.insert( {i, 1 + getCollatz(i/2)} );
    else
      storage.insert( {i, 1 + getCollatz(3*i + 1)} );
    iter = storage.find(i);
    return iter-> second;
  }
}

int main(){
  int length = 0;
  int result = 0;
  storage.insert( { 1, 1 } );

  for(int i = 1; i < 1000000; ++i){
    int temp = getCollatz(i);
    if(temp > length){
      length = temp; 
      result = i;
    }
  }  

  std::cout << result << std::endl;
}
