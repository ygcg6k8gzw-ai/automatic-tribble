
#include <iostream>
using namespace std;

int main() {
	int arr[10] = {34, 7, 19, 88, 5, 42, 103, 2, 67, 15};
	
	cout << "Элементы массива: ";
	for (int i = 0; i < 10; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
	
	
	int minVal = arr[0];
	int maxVal = arr[0];
	

	for (int i = 1; i < 10; ++i) {
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
		if (arr[i] > maxVal) {
			maxVal = arr[i];
		}
	}
	
	cout << "Минимальный элемент: " << minVal << endl;
	cout << "Максимальный элемент: " << maxVal << endl;
	
	return 0;
}

