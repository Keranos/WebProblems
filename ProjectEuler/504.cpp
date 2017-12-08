#include <iostream>
#include <math.h>
#include "MathFunctions.h"

int main(){
  unsigned int limit = 100;

  int boundary[limit + 1][limit + 1];

  for(int i = 1; i <= limit; i++)
    for(int j = 1; j <= limit; j++){
      boundary[i][j] = i == 0 || j == 0 ? 0 : gcd(i, j);
      if(i != j)
	boundary[j][i] = boundary[i][j];
      }

  int count = 0;

  for(int i = 1; i <= limit; i++)
    for(int j = 1; j <= limit; j++)
      for(int k = 1; k <= limit; k++)
	for(int l = 1; l <= limit; l++){
	  int edgePoint = boundary[i][j] + boundary[j][k]
	    + boundary[k][l] + boundary[l][i];

	  int area = (i + k) * (j + l) / 2;
	  int total = area - edgePoint / 2 + 1;

	  if((int)ceil(sqrt(total)) == (int)floor(sqrt(total)))
	    count++;
	  }
  
  std::cout << count << std::endl;
  return 0;
}
