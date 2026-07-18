
#include <iostream>
	 
	 int main() {
		 
		 std::cout << std::boolalpha;
		 
		 
		 bool vars[] = {true, false};
		 
		 std::cout << "Таблица истинности для && (логическое И)\n";
		 std::cout << "Var1\tVar2\tVar1 && Var2\n";
		 std::cout << "--------------------------\n";
		 
		 for (bool v1 : vars) {
			 for (bool v2 : vars) {
				 std::cout << v1 << "\t" << v2 << "\t" << (v1 && v2) << "\n";
			 }
		 }
		 
		 std::cout << "\nТаблица истинности для || (логическое ИЛИ)\n";
		 std::cout << "Var1\tVar2\tVar1 || Var2\n";
		 std::cout << "--------------------------\n";
		 
		 for (bool v1 : vars) {
			 for (bool v2 : vars) {
				 std::cout << v1 << "\t" << v2 << "\t" << (v1 || v2) << "\n";
			 }
		 }
		 
		 
		 int a = 10;
		 int b = 12;
		 int c = 8;
		 
		 std::cout << "\nПримеры с выражениями:\n";
		 std::cout << "(a < b) && (b > c): " << ((a < b) && (b > c)) << "\n"; // true && true
		 std::cout << "(a > b) && (b > c): " << ((a > b) && (b > c)) << "\n"; // false && true
		 std::cout << "(a > b) || (b > c): " << ((a > b) || (b > c)) << "\n"; // false || true
		 
		 return 0;
	 }
	 ```
	 

