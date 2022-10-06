#include <iostream>

bool is_prime(const int& n){
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	
	for (int i = 3; (i*i) <= n; i+=2)
		if (n % i == 0)
			return false;
		
	return true;
}

int main(){
	int n;
	while (std::cin >> n && n != 0){
		auto gap = 0;
		if (n % 2 == 0){
			if (n == 2)
				std::cout << gap << std::endl;
			else{
			gap = 2;
			auto up = n + 1;
			auto down = n - 1;
			while (!is_prime(up)){
				gap += 2;
				up += 2;
			}				
			while (!is_prime(down)){
				gap += 2;
				down -= 2;
			}				
			std::cout << gap << std::endl;
			}
		}
		else{
			if (is_prime(n)) 
				std::cout << gap << std::endl;
			else{
				auto up = n;
				auto down = n;
				while (!is_prime(up)){
					gap += 2;
					up += 2;
				}
				
				while (!is_prime(down)){
					gap += 2;
					down -= 2;
				}
				
				std::cout << gap << std::endl;
			}
		}
	}
}