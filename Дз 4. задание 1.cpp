
#include <iostream>

int main() {
	int number;
	int sum = 0; 
	while (true) {
		std::cin >> number;
		
		if (number == 0) {
			break;
		}
		
		sum += number;
	}
	
	std::cout << "Sum: " << sum << std::endl;
	
	return 0;
}



