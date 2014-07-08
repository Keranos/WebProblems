#include <vector>
#include <iostream>
#include <iterator>
#include <math.h>
#include <algorithm>
#include <list>
#include <iterator>
#include <fstream>

int main(){
  const int n = 1000001;

  typedef std::vector<bool> vector;
  vector self(n,true);
   
  //for(int i = 0; i < n; ++i)
  //  self.push_back(i+1);

  int j = 1, k, m, num, digit;
  vector::iterator iter;

  while(j < n){
    k = j; m = j;
    if(self[j]){
      std::cout << j << std::endl;
      while(k < n){
        num = log10(static_cast<double>(k));
        for(int l = 0; l <= num; ++l){
          digit = k % static_cast<int>(pow(10.0,static_cast<double>(l+1)))/pow(10.0,static_cast<double>(l));
          m += digit;
        }

        k = m;      
        if(m < n && self[m]) self[m] = false;
        else break;  
      }
    } 
    j++;
  }
}