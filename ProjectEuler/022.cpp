#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

// Read names from file and sum their letters and multiply by position.

std::vector<std::string> read_file(const std::string& path){
  std::ifstream file(path);

  if(!file.is_open()){
    std::cerr << "Unable to open file." << std::endl;
    std::exit(-1);
  }

  std::vector<std::string> words;
  std::string token;
  
  while(std::getline(file, token, ','))
    words.push_back(token);

  return words;
}

int convert_ascii_to_int(unsigned long t, int i){
  constexpr static int ascii_to_integer = 64;
  return t += i - ascii_to_integer;
}

int sum_word(const std::string& word){
  return std::accumulate(word.begin(), word.end(), 0, convert_ascii_to_int);
}

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
