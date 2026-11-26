#include <iostream>
#include <string>

struct BankAccount {
	int number;
	std::string owner;
	double balance;
};

void changeBalance(BankAccount& account, double newBalance) {
	account.balance = newBalance;
}

int main() {
	BankAccount account;
	
	std::cout << "Введите номер счёта: ";
	std::cin >> account.number;
	
	std::cout << "Введите имя владельца: ";
	std::cin >> account.owner;
	
	std::cout << "Введите баланс: ";
	std::cin >> account.balance;
	
	double newBalance;
	std::cout << "Введите новый баланс: ";
	std::cin >> newBalance;
	
	changeBalance(account, newBalance);
	
	std::cout << "Ваш счёт: " << account.owner << ", "
	<< account.number << ", " << account.balance << '\n';
	
	return 0;
}
