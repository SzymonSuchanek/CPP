#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <algorithm>
# include <iomanip>
# include <ctime>

template<typename T>
void printContainer(const T &container)
{
    for (size_t i = 0; i < container.size(); i++)
        std::cout << container[i] << " ";
    std::cout << std::endl;
}

class PmergeMe {
	
public:

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	
	static void fordJohnsonSort(std::vector<int>& vec);
    static void fordJohnsonSort(std::deque<int>& deq);
};

long long getTimeMicroseconds();
bool isPositiveInteger(const std::string& s);


#endif
