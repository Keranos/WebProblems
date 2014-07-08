#include <iostream>
#include <sstream>
 
using namespace std;
     
typedef unsigned int uint;
           
int main(){

  for (uint m, n; cin >> m >> n && !(m == 1 && n == 1); ) {
    stringstream sb;
    for (uint numerator = 1, denomenator = 1, ln = 0, ld = 1, rn = 1, rd = 0; 
         !(m == numerator && n == denomenator); ) {
      if (m * denomenator < n * numerator) { 
        sb << 'L';
        rn = numerator;
        rd = denomenator;
        numerator += ln;
        denomenator += ld;
      } else {
        sb << 'R';
        ln = numerator;
        ld = denomenator;
        numerator += rn;
        denomenator += rd;
      }
    } 
    cout << sb.str() << '\n';
  }
  return 0;
}