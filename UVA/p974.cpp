#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <algorithm>

using namespace std;

int main(){
  int storage[19] = {9, 45, 55, 99, 297, 703, 999 , 2223, 2728, 4879, 4950, 5050, 5292, 7272, 7777, 9999, 17344, 22222, 38962};
  vector<int> v;
  
  copy(storage, storage+19, std::back_inserter(v));

  int n, lower, upper, count = 0;
  cin >> n;
  
  vector<int>::iterator l_iter, u_iter;

  while(n--){
    cin >> lower >> upper;
    
    l_iter = find_if(v.begin(), v.end(), bind2nd(greater<int>(), lower-1));
    u_iter = find_if(v.begin(), v.end(), bind2nd(greater<int>(), upper+1));

    cout << "case #" << ++count << endl;

    if(l_iter != u_iter)
      for(;l_iter != u_iter; ++l_iter)
        cout << *l_iter << endl;
    else
      std::cout << "no kaprekar numbers" << endl;

    cout << endl;     
  }
}