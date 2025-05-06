#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <string>
# include <stdexcept>
# include <algorithm>

class PmergeMe {
	
public:

	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();
	
	static void fordJohnsonSort(std::vector<int>& vec);
    static void fordJohnsonSort(std::deque<int>& deq);

    static void printContainer(const std::vector<int>& vec);
    static void printContainer(const std::deque<int>& deq);

};

#endif
