#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

#include "TextOperations.h"

// Read names from file and sum their letters and multiply by position.

int total_word_position(const std::vector<std::string>& v){
  int counter = 1;
  int total = 0;
  
  for(const std::string& s : v){
    std::string word(s.begin() + 1, s.end() - 1);
    total += (sum_word(word) * counter);
    ++counter;
  }

  return total;
}

int main(){
  std::vector<std::string> words = read_file("names.txt");
  std::sort(words.begin(), words.end());
  int result = total_word_position(words);
  std::cout << result << std::endl;
}
