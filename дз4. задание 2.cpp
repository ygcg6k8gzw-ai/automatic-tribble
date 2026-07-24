
#include <iostream>

using namespace std;

int main() {
	int number;	
	cout << "Введите целое число: ";
	cin >> number;
	cout << "Таблица умножения для числа " << number << ":\n";
	for (int i = 1; i <= 10; ++i) {
		cout << number << " * " << i << " = " << number * i << endl;
	}
	
	return 0;
}

