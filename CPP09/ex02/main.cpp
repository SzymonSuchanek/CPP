#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    PmergeMe pmergeMe;
    std::vector<int> vector;
    std::deque<int> deque;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!isPositiveInteger(arg)) {
            std::cerr << "Error: Invalid number: " << arg << std::endl;
            return 1;
        }
        vector.push_back(std::atoi(argv[i]));
        deque.push_back(std::atoi(argv[i]));
    }

    std::cout << "Before: ";
    printContainer(vector);

    double start = getTimeMicroseconds();
    pmergeMe.fordJohnsonSort(vector);
    double end = getTimeMicroseconds();
    double elapsed = end - start;

    std::cout << "After: ";
    printContainer(vector);

    std::cout << "Time to process a range of " << vector.size()
              << " elements with std::vector: " << std::fixed << std::setprecision(5)<< static_cast<double>(elapsed) << " us" << std::endl;

    start = getTimeMicroseconds();
    pmergeMe.fordJohnsonSort(deque);
    end = getTimeMicroseconds();
    elapsed = end - start;

    std::cout << "Time to process a range of " << deque.size()
              << " elements with std::deque: " << std::fixed << std::setprecision(5) << elapsed << " us" << std::endl;

    return 0;
}
