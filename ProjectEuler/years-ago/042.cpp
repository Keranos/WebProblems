// Checking through the words.txt file, how many are triangle words 
// when you sum up the values of the word?

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "TextOperations.h"

int main(){
  std::vector<std::string> words = read_file("words.txt");
  int count = 0;

  for(const std::string& s : words){
    std::string word(s.begin() + 1, s.end() - 1);
    int sum = sum_word(word);
    double qrf = 0.5 * (sqrt(sum * 8.0 + 1.0) - 1.0);
    if(qrf == (int)qrf)
      count++;
  }

  std::cout << count << std::endl;
}
