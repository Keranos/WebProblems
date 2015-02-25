#include <iostream>
#include <map>
#include <list>
#include <string>
#include <math.h>

using namespace std;

int main(){
  int n, m, f;
  string g, t, r;
  bool firstOutput = true;

  while(cin >> n){
    list<string> names;
    map<string, int> wealth;
    for(int i = 0; i < n; ++i){
      cin >> g;
      names.push_back(g);
      wealth.insert(std::pair<string, int>(g, 0));
    }

    if(!firstOutput) cout << endl;
    else firstOutput = false;

    for(int i = 0; i < n; ++i){
      cin >> g >> m >> f;
      if(f != 0)
	wealth[g] -= (m - m % f);
	
      for(int j = 0; j != f; ++j){
	cin >> r;
	wealth[r] += m / f;
      }
    }
    
    for(list<string>::iterator i = names.begin(); i != names.end(); ++i)
      cout << *i << " " << wealth[*i] << endl;
  }
}
