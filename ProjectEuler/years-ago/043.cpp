// Find the sum of all 0 to 9 pandigital numbers with the property that
// d2d3d4 % 2 == 0, d3d4d5 % 3 == 0, d4d5d6 % 5 == 0, d5d6d7 % 7 ==0,
// d6d7d8 % 11 == 0, d7d8d9 % 13 == 0 and d8d9d10 % 17 == 0.

#include <iostream> 
#include <algorithm>
#include <vector>

typedef std::vector<int> vec;

unsigned long convert_to_int(vec& v){
  unsigned long result = 0;
  unsigned mult = 1;
  for(vec::reverse_iterator i = v.rbegin(); i != v.rend(); ++i){
    result += *i * mult;
    mult *= 10;
  }
  
  return result;
}

int main(){
  vec numbers {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  unsigned long result = 0;
  
  while(std::next_permutation(numbers.begin(), numbers.end()))
    if(numbers[5] == 5)
      if(numbers[3] % 2 == 0)
	if((numbers[2] + numbers[3] + numbers[4]) % 3 == 0)
	  if((numbers[7]*100 + numbers[8]*10 + numbers[9]) % 17 == 0)
	    if((numbers[6]*100 + numbers[7]*10 + numbers[8]) % 13 == 0)
	      if((numbers[5]*100 + numbers[6]*10 + numbers[7]) % 11 == 0)
		if((numbers[4]*100 + numbers[5]*10 + numbers[6]) % 7 == 0)
		  result +=  convert_to_int(numbers);

  std::cout << result << std::endl;
}
