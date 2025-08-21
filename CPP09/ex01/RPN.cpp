#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}

RPN::~RPN() {}

void RPN::calculate(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token)
    {
        if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
            _stack.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top();
            _stack.pop();
            int a = _stack.top();
            _stack.pop();

            if (token == "+")
                _stack.push(a + b);
            else if (token == "-")
                _stack.push(a - b);
            else if (token == "*")
                _stack.push(a * b);
            else if (token == "/")
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                _stack.push(a / b);
            }
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}
