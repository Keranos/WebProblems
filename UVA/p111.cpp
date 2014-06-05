#include <iostream>
#include <algorithm>

int main(){
  int n;
  int a[21] = {0}, b[21] = {0};

  std::cin >> n;

  int t;
  for(int i = 1; i <= n; ++i){
    std::cin >> t;
    a[t] = i;
  }

  while(true){
    int m[21][21] = {0};
    for(int i = 1; i <= n; ++i){
      std::cin >> t;
      b[t] = i;
    }

    for(int i = 1; i <= n; ++i)
      for(int j = 1; j <= n; ++j)
	if(a[i] == b[j])
	  m[i][j] = m[i-1][j-1] + 1;
        else 
	  m[i][j] = std::max(m[i-1][j], m[i][j-1]);

    std::cout << m[n][n] << std::endl;
    }

}
