// If p is a perimeter of a right angle triangle, {a, b, c}, which 
// value for p =< 1000, has the most solutions?

#include <iostream>

int main(){
  int result = 0, tSolutions = 0;
  
  for(int p = 2; p <= 1000; p += 2){
    int nSolutions = 0;
    for(int a = 2; a < p/3; ++a){
      if(p*(p - 2*a) % (2 * (p - a)) == 0)
	nSolutions++;
    }
    if(nSolutions > tSolutions){
      tSolutions = nSolutions;
      result = p;
    }
  }

  std::cout << result << std::endl;
}
