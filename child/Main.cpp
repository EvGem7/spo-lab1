#include <iostream>
#include <Windows.h>

const size_t arraySize = 10;

int main(int argc, char* argv[]) {
	std::cout << "countdown!" << std::endl;
	Sleep(1300);
	int array[arraySize];
	for (int i = 0; i < arraySize; ++i) {
		array[i] = i;
		std::cout << arraySize - i << std::endl;
		Sleep(400);
	}
	std::cout << "array is ready!" << std::endl;
	for (int& a : array) {
		std::cout << a << ' ';
	}
	std::cout << std::endl;
	system("pause > NUL");
	return 0;
}