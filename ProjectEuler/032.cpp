// Find the sum of all products whose multiplicand/multiplier/product
// identity can be written as a 1 through 9 pandigital

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

int main(){
  std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  std::set<int> result;

  do{
    int m1 = v[0];
    int n1 = v[1]*1000 + v[2]*100 + v[3]*10 + v[4];
    int p1 = v[5]*1000 + v[6]*100 + v[7]*10 + v[8];
    if(m1 * n1 == p1) result.insert(p1);

    int m2 = v[0]*10 + v[1];
    int n2 = v[2]*100 + v[3]*10 + v[4];
    int p2 = v[5]*1000 + v[6]*100 + v[7]*10 + v[8];
    if(m2 * n2 == p2) result.insert(p2);

  }while(std::next_permutation(v.begin(), v.end()));

  int sum = std::accumulate(result.begin(), result.end(), 0);
  std::cout << sum << std::endl;
}
