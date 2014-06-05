#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
  int start, height, end;
  vector<int> Skyline(10001, 0);
  
  while((cin >> start >> height >> end) && !cin.eof())
    replace_if(Skyline.begin()+start, Skyline.begin()+end, bind2nd(less<int>(), height),height);

  vector<int>::iterator ibegin = Skyline.begin(), iend = Skyline.end();
  vector<int>::iterator ipos = ibegin+1;
  
  while(ipos != iend){
    cout << distance(ibegin, ipos) << " " << *ipos << " ";
    ipos = find_if(ipos, iend, bind2nd(not_equal_to<int>(), *ipos));
  }

  if(*ipos != 0)
    cout << "0";
}

