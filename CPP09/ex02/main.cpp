#include "PmergeMe.hpp"
#include <cstdlib>
#include <string>
#include <sys/time.h>

// Function to get the current time in microseconds
long getTimeMicroseconds() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return static_cast<long>(tv.tv_sec) * 1000000 + static_cast<long>(tv.tv_usec);
}

// Check if a string is a valid positive integer
bool isPositiveInteger(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i)
        if (!std::isdigit(s[i]))
            return false;
    return true;
}

// Sort function using the Ford-Johnson sorting algorithm for vectors
void fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() <= 1)
        return;

    std::vector<int> mainChain;
    std::vector<int> pending;

    for (std::size_t i = 0; i + 1 < vec.size(); i += 2) {
        int a = vec[i];
        int b = vec[i + 1];
        if (a > b) std::swap(a, b);
        mainChain.push_back(b);
        pending.push_back(a);
    }

    if (vec.size() % 2 != 0)
        pending.push_back(vec[vec.size() - 1]);

    std::sort(mainChain.begin(), mainChain.end());

    for (std::size_t i = 0; i < pending.size(); ++i) {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }

    vec = mainChain;
}

// Print function for vector
void printContainer(const std::vector<int>& container) {
    const std::size_t maxDisplay = 5;
    for (std::size_t i = 0; i < container.size() && i < maxDisplay; ++i) {
        std::cout << container[i] << " ";
    }
    if (container.size() > maxDisplay)
        std::cout << "[...]";
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    std::vector<int> input;

    // Populate input from command-line arguments, taking only the first 5 values
    for (int i = 1; i < argc && i <= 5; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error: Invalid number: " << arg << std::endl;
            return 1;
        }
        input.push_back(std::atoi(argv[i]));
    }

    // Check if exactly 5 values were provided
    if (input.size() != 5) {
        std::cerr << "Error: You must provide exactly 5 values." << std::endl;
        return 1;
    }

    // Print Before using the original input
    std::cout << "Before: ";
    printContainer(input);

    // Make a copy of the original input for sorting
    std::vector<int> sortedInput(input.begin(), input.end());

    // Sort the input
    long startVec = getTimeMicroseconds();
    fordJohnsonSort(sortedInput);
    long endVec = getTimeMicroseconds();

    // Print After (sorted)
    std::cout << "After: ";
    printContainer(sortedInput);

    // Time results
    std::cout << "Time to process a range of " << input.size()
              << " elements with std::vector: " << endVec - startVec << ".00000 us" << std::endl;

    return 0;
}