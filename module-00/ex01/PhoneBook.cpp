#include "phonebook.hpp"

PhoneBook::PhoneBook() { this->index = 0; }

PhoneBook::~PhoneBook() { };

void PhoneBook::add()
{
	std::string name;
	std::cout << "Name : ";
	std::cin >> name;

	std::string last_name;
	std::cout << "Last Name : ";
	std::cin >> last_name;

	std::string nick_name;
	std::cout << "Nickname : ";
	std::cin >> nick_name;

	std::string number;
	std::cout << "Number : ";
	std::cin >> number;

	std::string secret;
	std::cout << "Secret : ";
	std::cin >> secret;

	std::cout << CONTACT_ADDED << std::endl;
	this->Info[this->index++] = ContactInfo( name, last_name, nick_name, number, secret);
	if (this->index > 7) { this->index = 0; }
}

std::string	tronc( std::string str, size_t size ) {
	if (str.length() > size) {
		return str.substr(0, size - 1) + ".";
	}
	return str;
}

void PhoneBook::search()
{
	for (int i = 0; i < 8; i++) {
		std::cout << std::left << std::setw(10) << i + 1;
		std::cout << "|";
		std::cout << std::left << std::setw(10) << tronc(this->Info[i].name, 10);
		std::cout << "|";
		std::cout << std::left << std::setw(10) << tronc(this->Info[i].surname, 10);
		std::cout << "|";
		std::cout << std::left << std::setw(10) << tronc(this->Info[i].nickname, 10);
		std::cout<< std::endl;
	}
}

void PhoneBook::print() {

	int			index;
	std::string	line;
	std::cout << ASK_INDEX << std::endl;
	std::cin >> line;
	if (line < "1" || line > "8") { std::cout << BAD_INDEX << std::endl; return ; }
	index = std::stoi(line);
	std::cout << "Name : " << this->Info[index - 1].name << std::endl;
	std::cout << "Last Name : " << this->Info[index - 1].surname << std::endl;
	std::cout << "Nickname : " << this->Info[index - 1].nickname << std::endl;
	std::cout << "Number : " << this->Info[index - 1].number << std::endl;
	std::cout << "Secret : " << this->Info[index - 1].secret << std::endl;
}