#include "PmergeMe.hpp"
#include <cstdlib>
#include <string>
#include <sys/time.h>
// Utility function to check if a string is a positive integer
bool isPositiveInteger(const std::string& s) {
    if (s.empty())
        return false;
    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

// Utility function to get the current time in microseconds
long getTimeMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<long>(tv.tv_sec) * 1000000 + static_cast<long>(tv.tv_usec);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    // Store original input here
    std::vector<int> input;

    // Validate and populate input
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        input.push_back(std::atoi(argv[i]));
    }

    // Make copies of the original input for vector and deque
    std::vector<int> vectorInput(input.begin(), input.end());
    std::deque<int> dequeInput(input.begin(), input.end());

    // Print Before using original input
    std::cout << "Before: ";
    PmergeMe::printContainer(input);

    // Sort vector
    long startVec = getTimeMicroseconds();
    PmergeMe::fordJohnsonSort(vectorInput);
    long endVec = getTimeMicroseconds();

    // Print After (sorted vector)
    std::cout << "After: ";
    PmergeMe::printContainer(vectorInput);

    // Sort deque
    long startDeq = getTimeMicroseconds();
    PmergeMe::fordJohnsonSort(dequeInput);
    long endDeq = getTimeMicroseconds();

    // Time results
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector: " << endVec - startVec << ".00000 us" << std::endl;

    std::cout << "Time to process a range of " << input.size()
              << " elements with std::deque: " << endDeq - startDeq << ".00000 us" << std::endl;

    return 0;
}