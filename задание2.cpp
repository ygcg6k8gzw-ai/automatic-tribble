#include <iostream>
#include <string>

struct Address {
	std::string city;
	std::string street;
	int houseNumber;
	int apartmentNumber;
	int postalCode;
};

void printAddress(const Address& address) {
	std::cout << "Город: " << address.city << '\n'
	<< "Улица: " << address.street << '\n'
	<< "Номер дома: " << address.houseNumber << '\n'
	<< "Номер квартиры: " << address.apartmentNumber << '\n'
	<< "Индекс: " << address.postalCode << '\n';
}

int main() {
	Address first{"Москва", "Арбат", 12, 8, 123456};
	Address second{"Ижевск", "Пушкина", 59, 143, 953769};
	
	printAddress(first);
	std::cout << '\n';
	printAddress(second);
	
	return 0;
}
