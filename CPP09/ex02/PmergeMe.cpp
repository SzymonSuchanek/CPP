#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) { 
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::fordJohnsonSort(std::vector<int>& vec) {
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

void PmergeMe::fordJohnsonSort(std::deque<int>& deq) {
    if (deq.size() <= 1)
        return;

    std::deque<int> mainChain;
    std::deque<int> pending;

    for (std::size_t i = 0; i + 1 < deq.size(); i += 2) {
        int a = deq[i];
        int b = deq[i + 1];
        if (a > b) std::swap(a, b);
        mainChain.push_back(b);
        pending.push_back(a);
    }

    if (deq.size() % 2 != 0)
        pending.push_back(deq[deq.size() - 1]);

    std::sort(mainChain.begin(), mainChain.end());

    for (std::size_t i = 0; i < pending.size(); ++i) {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pending[i]);
        mainChain.insert(pos, pending[i]);
    }

    deq = mainChain;
}

void PmergeMe::printContainer(const std::vector<int>& container) {
    const std::size_t maxDisplay = 5;
    for (std::size_t i = 0; i < container.size() && i < maxDisplay; ++i) {
        std::cout << container[i] << " ";
    }
    if (container.size() > maxDisplay)
        std::cout << "[...]";
    std::cout << std::endl;
}

void PmergeMe::printContainer(const std::deque<int>& container) {
    const std::size_t maxDisplay = 5;
    for (std::size_t i = 0; i < container.size() && i < maxDisplay; ++i) {
        std::cout << container[i] << " ";
    }
    if (container.size() > maxDisplay)
        std::cout << "[...]";
    std::cout << std::endl;
}