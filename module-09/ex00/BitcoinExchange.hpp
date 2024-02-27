#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <exception>
#include <iterator>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange {

public: 
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange();
		BitcoinExchange& operator= (const BitcoinExchange &copy); 

		void			parseData(std::fstream &data);
		void			readInput(std::fstream &data);

private:
	bool			checkFormat(std::string pattern, std::string str);
	bool			checkDate(int date);

	std::map<int, float> data;

	class EmptyDataFileException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InvalidFormatException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InvalidDataDateException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InvalidDataPriceException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InvalidDataFormatException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
	class InvalidPatternFormat : public std::exception {
		public:
			virtual const char *what() const throw();
	};

};

#endif