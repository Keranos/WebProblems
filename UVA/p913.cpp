#include <iostream>

int main(){
	unsigned long long int in, sum, num;
	while(std::cin >> in){
		num = (in-1)/2;
		sum = 15 + 30*(num-1) + 6*(num-1)*(num-2);
		std::cout << sum << std::endl;
	}
}

