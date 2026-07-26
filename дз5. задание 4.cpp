#include <iostream>

int main() {
	
	int arr[] = {34, 7, 23, 32, 5, 62, 78, 1, 9, 15};
	const int n = 10;
	
	std::cout << "Массив до сортировки: ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	
	for (int i = 0; i < n - 1; ++i) {
	
		bool swapped = false;
		for (int j = n - 1; j > i; --j) {
		
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				swapped = true;
			}
		}
		
		if (!swapped) break;
	}
	
	std::cout << "Массив после сортировки (по возрастанию): ";
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
	
	return 0;
}

