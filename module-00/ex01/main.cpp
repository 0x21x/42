#include "phonebook.hpp"

int main( void ) {
	PhoneBook PhoneBook;
	std::string	line;

	for (;;) {
		std::cout << PROMPT;
		std::cin >> line;
		if (line == "EXIT") { break; }
		else if (line == "ADD") { PhoneBook.add(); }
		else if (line == "SEARCH") { PhoneBook.search(); PhoneBook.print(); }
	}
	return 0;
}