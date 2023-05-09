# include <iostream>
# include <string>

int main( void ) {
	std::string line = "HI THIS IS BRAIN";
	std::string *ptr = &line;
	std::string &ref = line;
	
	std::cout << "Adress" << std::endl;
	std::cout << "Base		: " << &line << std::endl;
	std::cout << "StringPtr	: " << &ptr << std::endl;
	std::cout << "StringRef	: " << &ref << std::endl;
	std::cout << std::endl;
	std::cout << "Value" << std::endl;
	std::cout << "Base		: " << line << std::endl;
	std::cout << "StringPtr	: " << *ptr << std::endl;
	std::cout << "StringRef	: " << ref << std::endl;

}
