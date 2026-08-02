
#include <iostream>
	
	int power(int base, int exp) {
	int result = 1;
	for (int i = 0; i < exp; ++i) {
		result *= base;
	}
	return result;
}

int main(int argc, char** argv) {
	int value = 5;
	int power_val = 2;
	std::cout << value << " в степени " << power_val << " = " 
	<< power(value, power_val) << std::endl;
	
	value = 3;
	power_val = 3;
	std::cout << value << " в степени " << power_val << " = " 
	<< power(value, power_val) << std::endl;
	
	value = 4;
	power_val = 4;
	std::cout << value << " в степени " << power_val << " = " 
	<< power(value, power_val) << std::endl;
	
	return 0;
}



