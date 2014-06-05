// 417 - WordIndex
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>

int main(){
  std::map<int, std::string> alphabet;
  alphabet[1] = "a"; alphabet[2] = "b";
  alphabet[3] = "c"; alphabet[4] = "d";
  alphabet[5] = "e"; alphabet[6] = "f";
  alphabet[7] = "g"; alphabet[8] = "h";
  alphabet[9] = "i"; alphabet[10] = "j";
  alphabet[11] = "k"; alphabet[12] = "l";
  alphabet[13] = "m"; alphabet[14] = "n";
  alphabet[15] = "o"; alphabet[16] = "p";
  alphabet[17] = "q"; alphabet[18] = "r";
  alphabet[19] = "s"; alphabet[20] = "t";
  alphabet[21] = "u"; alphabet[22] = "v";
  alphabet[23] = "w"; alphabet[24] = "x";
  alphabet[25] = "y"; alphabet[26] = "z";

  int index = 0;
  std::vector<std::string> storage(83681);

  for(int i = 1; i < 27; ++i){
    storage[index] = alphabet.find(i)->second; index++; }
  for(int i = 1; i < 27; ++i)
    for(int j = i+1; j < 27; ++j){
      storage[index] = (alphabet.find(i)->second + alphabet.find(j)->second); index++; }
  for(int i = 1; i < 27; ++i)
    for(int j = i+1; j < 27; ++j) 
      for(int k = j+1; k < 27; ++k){
        storage[index] = (alphabet.find(i)->second + alphabet.find(j)->second + 
                          alphabet.find(k)->second); index++; }
  for(int i = 1; i < 27; ++i)
    for(int j = i+1; j < 27; ++j) 
      for(int k = j+1; k < 27; ++k)
        for(int l = k+1; l < 27; ++l){
      storage[index] = (alphabet.find(i)->second + alphabet.find(j)->second + 
                        alphabet.find(k)->second + alphabet.find(l)->second); index++; }
  for(int i = 1; i < 27; ++i)
    for(int j = i+1; j < 27; ++j) 
      for(int k = j+1; k < 27; ++k)
        for(int l = k+1; l < 27; ++l)
          for(int m = l+1; m < 27; ++m){
      storage[index] = (alphabet.find(i)->second + alphabet.find(j)->second + 
                        alphabet.find(k)->second + alphabet.find(l)->second + 
                        alphabet.find(m)->second); index++; }


  std::string s;
  std::vector<std::string>::iterator iter;  

  while(std::cin >> s){
    iter = std::find(storage.begin(), storage.end(), s);
    if(iter == storage.end())
      std::cout << "0" << std::endl;
    else
      std::cout << iter - storage.begin() + 1 << std::endl;
  }
}