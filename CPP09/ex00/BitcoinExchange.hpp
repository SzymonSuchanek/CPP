#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <map>
# include <fstream>
# include <string>
# include <sstream>
# include <cstdlib>
# include <limits>
# include <algorithm>

class BitcoinExchange {
private:
    std::map<std::string, double> _rates;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    int loadDatabase(const std::string &filename);
    int processInput(const std::string &filename);

private:
    bool isValidDate(const std::string &date) const;
    bool isValidValue(const std::string &valueStr, float &value) const;
    std::string trim(const std::string &str) const;
    double getRateForDate(const std::string &date) const;
};

#endif
