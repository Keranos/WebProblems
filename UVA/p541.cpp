#include <iostream>
#include <vector>

int main(){
  int size, input;
  int mat[100][100];

  while(std::cin >> size && size != 0){
    for(int i = 0; i != size; ++i)
      for(int j = 0; j != size; ++j){
        std::cin >> input;
        mat[i][j] = input;
      }
  
    std::vector<int> row;
    std::vector<int> col;

    for(int i = 0; i != size; ++i){
      int row_sum = 0;
      int col_sum = 0;
      for(int j = 0; j != size; ++j){
        row_sum += mat[i][j];
        col_sum += mat[j][i];
      }
      if(row_sum % 2 != 0) row.push_back(i);
      if(col_sum % 2 != 0) col.push_back(i);
    } 

    if(row.empty() && col.empty()) std::cout << "OK" << std::endl;
    else if(row.size() == 1 && col.size() == 1) 
      std::cout << "Change bit (" << row[0]+1 << "," << col[0]+1 << ")" << std::endl;
    else std::cout << "Corrupt" << std::endl;
  }
}