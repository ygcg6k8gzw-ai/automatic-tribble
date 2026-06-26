#include <iostream>
#include <locale>

int main() {
	setlocale(LC_CTYPE, "rus");
	std::cout <<"Введите число"<< std::endl;
	int number = 957;
	std::cin >> number;
	std::cout <<"Вы ввели:"<<number <<std::endl;

}
	
