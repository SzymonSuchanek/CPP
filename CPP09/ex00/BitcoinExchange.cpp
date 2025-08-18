#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
    this->_rates = copy._rates;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other)
        this->_rates = other._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

int BitcoinExchange::loadDatabase(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open exchange rate database file." << std::endl;
        return 1;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::string::size_type pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));

        std::stringstream ss(valueStr);
        double rate;
        ss >> rate;

        if (!ss.fail())
            _rates[date] = rate;
    }

    file.close();
    return 0;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char dash1, dash2;
    std::stringstream ss(date);
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (ss.fail() || dash1 != '-' || dash2 != '-')
        return false;

    if (year < 1000 || year > 2025 || month < 1 || month > 12 || day < 1)
        return false;

    static const int daysInMonth[] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    int maxDay = daysInMonth[month];
    if (month == 2 &&
        ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        maxDay = 29;

    return day <= maxDay;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const {
    std::stringstream ss(valueStr);
    ss >> value;

    if (ss.fail() || !ss.eof()) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value < 0) {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }

    if (value > 1000) {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

std::string BitcoinExchange::trim(const std::string &str) const {
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

double BitcoinExchange::getRateForDate(const std::string &date) const {
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
    if (it == _rates.end() || it->first != date) {
        if (it == _rates.begin())
            return 0;
        --it;
    }
    return it->second;
}

int BitcoinExchange::processInput(const std::string &filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line)) {
        std::string::size_type pos = line.find('|');
        if (pos == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        float value;

        if (!isValidDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        if (!isValidValue(valueStr, value)) {
            continue;
        }

        double rate = getRateForDate(date);
        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }

    file.close();
    return 0;
}
