#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    *this = copy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator= (const BitcoinExchange &copy) {
    if (this != &copy) {
        this->data = copy.data;
    }
    return *this;
}

/**
 * The function checks if a given string matches a given pattern, where the pattern can contain
 * wildcard characters represented by '*'.
 * 
 * @param pattern The pattern parameter is a string that represents a pattern to match against another
 * string. It can contain any combination of characters and can include a '*' character, which acts as
 * a wildcard.
 * @param str The `str` parameter is a string that represents the input that needs to be checked
 * against the given pattern.
 * 
 * @return a boolean value.
 */
bool    BitcoinExchange::checkFormat(std::string pattern, std::string str) {
    if (pattern.find('*') == std::string::npos)
        throw BitcoinExchange::InvalidPatternFormat();

    std::string::iterator itS = str.begin();
    std::string::iterator it = pattern.begin();
    for (;it != pattern.end();) {
        if (*it == '#' && it++ != str.end()) {
            for (;std::strchr("-0123456789.", *itS) && itS != str.end(); itS++);
            continue;
        }
        if (*it == '*' && it++ != str.end()) {
            for (;std::strchr("0123456789.", *itS) && itS != str.end(); itS++);
            continue;
        }
        it++;
        itS++;
    }
    return (itS == str.end() && it == pattern.end());
}

/**
 * The function checks if a given date is valid.
 * 
 * @param date The parameter `date` represents a date in the format YYYYMMDD, where YYYY is the year,
 * MM is the month, and DD is the day.
 * 
 * @return a boolean value.
 */
bool    BitcoinExchange::checkDate(int date) {
    int year, month, day;

    year = date / 10000;
    date %= 10000;
    month = date / 100;
    date %= 100;
    day = date;

    if (year < 1 || year > 2023)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    if (month == 2 && day > (!(year % 4) && year % 100 ? 29 : 28))
        return false;
    if ((month == 1 || month == 3 || month == 5 || month == 7 ||
        month == 8 || month == 10 || month == 12) && day > 31)
        return false;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;
    return true;
}

/**
 * The function parseData reads data from a file, checks its format, and stores it in a map.
 * 
 * @param data The parameter "data" is a reference to an std::fstream object. It is used to read data
 * from a file.
 */
void    BitcoinExchange::parseData(std::fstream &data) {

    std::string line;
    std::getline(data, line, '\n');
    if (line != "date,exchange_rate")
        throw BitcoinExchange::InvalidFormatException();

    for (;std::getline(data, line);) {
        if (line.empty() && !this->data.size())
            throw BitcoinExchange::EmptyDataFileException();
        if (!this->checkFormat("*-*-*,*", line))
            throw BitcoinExchange::InvalidDataFormatException();
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());
        int date = std::stoi(::strndup(line.c_str(), line.find(',')));
        if (!this->checkDate(date))
            throw BitcoinExchange::InvalidDataDateException();
        float price = std::stof(line.substr(line.find(',') + 1));
        if (price > INT32_MAX)
            throw BitcoinExchange::InvalidDataPriceException();
        this->data[date] = price;
    }
}

/**
 * The function readInput reads input from a file, checks the format of each line, performs
 * calculations based on the input, and prints the results.
 * 
 * @param input The `input` parameter is a reference to an `std::fstream` object. It is used to read
 * input from a file.
 */
void    BitcoinExchange::readInput(std::fstream &input) {
    std::string line;
    std::getline(input, line, '\n');
    if (line != "date | value")
        throw BitcoinExchange::InvalidFormatException();

    for (;std::getline(input, line);) {
        if (!this->checkFormat("*-*-* | #", line)) {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        float multiplier = std::stof(line.substr(line.find('|') + 2));
        if (multiplier > 1000) {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        if (multiplier < 0) {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        
        std::string datetime = ::strndup(line.c_str(), line.find('|') - 1);
        line.erase(std::remove(line.begin(), line.end(), '-'), line.end());

        int date = std::stoi(::strndup(line.c_str(), line.find('|') - 1));
        if (!this->checkDate(date)) {
            std::cout << "Error: not a valid date." << std::endl;
            continue;
        }
        
        std::map<int, float>::iterator it = this->data.find(date);
        if (it != this->data.end())
            it = this->data.find(date);
        else
            it = this->data.lower_bound(date);
        float result = it->second * multiplier;

        std::cout << datetime << " => " << multiplier << " = " << result << std::endl;
    }
}

const char *BitcoinExchange::EmptyDataFileException::what() const throw() {
    return "Error: Empty data file.";
}

const char *BitcoinExchange::InvalidFormatException::what() const throw() {
    return "Error: Invalid file format.";
}

const char *BitcoinExchange::InvalidDataDateException::what() const throw() {
    return "Error: Invalid date in data file.";
}

const char *BitcoinExchange::InvalidDataPriceException::what() const throw() {
    return "Error: Invalid price in data file.";
}

const char *BitcoinExchange::InvalidDataFormatException::what() const throw() {
    return "Error: Invalid data file format.";
}

const char *BitcoinExchange::InvalidPatternFormat::what() const throw() {
    return "Error: Invalid pattern format.";
}

