#include <iostream>

int main(){
  const int n = 9;
  int aa[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int cur = 0;
  int sum = 0;

  for(int i = 0; i != n; ++i){
    sum += aa[i];
    if(sum > cur)
      cur = sum;
    else if(sum < 0)
      sum = 0;
  }
  std::cout << cur << std::endl;

  int N;
  short int t = 0;
  short int a[100][100];
  short int pr[100];
  int S = 1<<31, s = 0;

  std::cin >> N;

  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      std::cin >> a[i][j];
 
  for( int z = 0; z < N; z++){
    for(int i = 0; i < N; i++) pr[i] = 0;
    for(int x = z; x < N; x++){
      t = 0;
      s = 1<<31;
      for(int i = 0; i < N; i++){
        pr[i] += a[x][i];
        t = t + pr[i];
        if( t > s)
          s = t;
        if( t < 0 )
          t = 0;
      }
      if( s > S)
        S = s;
    } 
  }
 
  std::cout << S << std::endl;
}