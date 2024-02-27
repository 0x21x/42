#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }

    std::fstream input;
    input.open(argv[1]);
    if (!input) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    std::fstream data;
    data.open("data.csv");
    if (!data) {
        std::cout << "Error: could not find the data file." << std::endl;
        return 1;
    }

    BitcoinExchange btc;
    try {
        btc.parseData(data);
        btc.readInput(input);
    }
    catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

