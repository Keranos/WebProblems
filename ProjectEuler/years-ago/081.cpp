#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

typedef unsigned long long ull;

const int n = 80;

using namespace std;

void split(const string &s, char delim, vector<string> & elems){
  stringstream ss;
  ss.str(s);
  string item;
  while(getline(ss, item, delim)){
    elems.push_back(item);
  }
}

vector<string> split(const string &s, char delim){
  vector<string> elems;
  split(s, delim, elems);
  return elems;
}

template <size_t rows, size_t cols>
void read_file(const std::string& path, ull (&array)[rows][cols]){
  std::ifstream file(path);

  if(!file.is_open()){
    std::cerr << "Unable to open file." << std::endl;
  }

  std::string x;

  int nRow = 0;
  int nCol = 0;
  
  while(getline(file, x)){
    vector<string> numbers = split(x, ',');
      
    for(int i = 0; i < n; i++){
      array[nRow][i] = stoi(numbers[i]);
    }
    
    nRow++;
  }
}

template<size_t rows, size_t cols>
ull solve(ull (&array)[rows][cols]){
  for(int i = n-1; i >= 0; i--){
    for(int j = n-1; j >= 0; j--){
      if(j == n-1 && i == n-1)
	continue;
      if(j == n-1)
	array[i][j] += array[i+1][j];
      else if(i == n-1){
	array[i][j] += array[i][j+1];
      }
      else{
	ull right = array[i][j] + array[i+1][j];
	ull bottom = array[i][j] + array[i][j+1];
	array[i][j] = right > bottom ? bottom : right;
      }
    }
  }

  return array[0][0];
}

int main(){
  ull matrix[80][80];
  read_file("p081_matrix.txt", matrix);
  ull output = solve(matrix);
  std::cout << output << std::endl;
}
