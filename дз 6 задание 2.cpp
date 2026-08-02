#include <iostream>


int fibonacci(int n)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	
	return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
	int count;
	
	std::cout << "Введите количество чисел последовательности Фибоначчи для вывода: ";
	std::cin >> count;
	
	if (count <= 0) {
		std::cout << "Количество чисел должно быть положительным." << std::endl;
		return 0;
	}
	
	std::cout << "Последовательность Фибоначчи: ";
	
	for (int i = 0; i < count; ++i) {
		std::cout << fibonacci(i) << " ";
	}
	
	std::cout << std::endl;
	
	return 0;
}

