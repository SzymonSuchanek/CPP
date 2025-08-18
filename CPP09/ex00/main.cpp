#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
	if (argc != 2) {
		std::cerr << "Error: as the only argument use the filename of the input file." << std::endl;
		return 1;
	}

	BitcoinExchange exchange;

	if (exchange.loadDatabase("data.csv") != 0) {
		std::cerr << "Error: failed to load exchange rates from data.csv." << std::endl;
		return 1;
	}

	if (exchange.processInput(argv[1]) != 0) {
		std::cerr << "Error: failed to process input file: " << argv[1] << std::endl;
		return 1;
	}

	return 0;
}
