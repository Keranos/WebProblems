// #133 DoleQueue
#include <iostream>
#include <vector>

int main(){
  int N, k, m;
  int lc, lw;
  std::vector<int> people;

  while( std::cin >> N >> k >> m && (N != 0 && k != 0 && m != 0) ){
    for(int i = 1; i <= N; ++i) people.push_back(i);

    lc = 0; lw = N-1;
    while(int(people.size())>0){
      lc+=k-1;
      lw-=m-1;
      while(lc>=people.size()) lc-=people.size();
      while(lw<0) lw+=people.size();
      if(lc==lw){
        printf("%3d",people[lc]);
        people.erase(people.begin()+lc);
        lw--;
      }
      else{
        printf("%3d%3d",people[lc],people[lw]);
        if(lc>lw) {people.erase(people.begin()+lc);lc--; people.erase(people.begin()+lw); lw--;}
        else {people.erase(people.begin()+lw); people.erase(people.begin()+lc); lw-=2;}
      }
      if(int(people.size())>0) putchar(',');
    }
    putchar(10);
  }
}