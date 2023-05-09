#include "Array.hpp"

#define MAX_VAL 10
int main(void)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++) {
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}

	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++) {
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try {
		numbers[-2] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}
	try {
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand();
	}
	delete [] mirror;
	
	Array<int> numbers2(MAX_VAL);
	for (int i = 0; i < MAX_VAL; i++) {
		numbers2[i] = rand() % 100;
	}
	for (int i = 0; i < MAX_VAL; i++) {
		numbers[i] = rand() % 100;
	}
	std::cout << "numbers1: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "numbers2: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers2[i] << std::endl;
	}
	std::cout << "numbers1 = numbers2" << std::endl;
	std::cout << std::endl;
	numbers = numbers2;
	std::cout << "numbers1: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "numbers2: " << std::endl;
	for (int i = 0; i < MAX_VAL; i++) {
		std::cout << numbers2[i] << std::endl;
	}
	return 0;
}