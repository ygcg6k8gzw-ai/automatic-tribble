#include <iostream>

int main() {
	int a = 5, b = 3, c = 1;  
	
	std::cout << std::boolalpha;
	
	bool Var1 = true;
	bool Var2 = false;
	
	std::cout << "(a > b) || (b > c): " << ((a > b) || (b > c)) << std::endl;
	std::cout << "(a < b) || (b > c): " << ((a < b) || (b > c)) << std::endl;
	std::cout << "(a < b) || (b < c): " << ((a < b) || (b < c)) << std::endl;
	
	return 0;
}

