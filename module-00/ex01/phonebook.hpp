#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include "ContactInfo.hpp"

const std::string PROMPT		= "\e[1;30mEnter a command : \e[0m";
const std::string BAD_COMMAND	= "\e[1;31mThe command isn't valid.\e[0m";
const std::string BAD_INDEX		= "\e[1;31mThe index isn't valid.\e[0m";
const std::string INDEX_EMPTY	= "\e[1;31mThe index contact is empty.\e[0m";
const std::string CONTACT_ADDED	= "\e[1;32mContact has been added !\e[0m";
const std::string ASK_INDEX		= "\e[1;30mEnter an index for more info about a contact.\e[0m";

class PhoneBook {

	public:

		PhoneBook();
		~PhoneBook();

		ContactInfo	Info[8];

		int		index;

		void	add();
		void	search();
		void	print();

};

#endif