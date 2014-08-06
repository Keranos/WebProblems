#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "FileOperations.h"

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
