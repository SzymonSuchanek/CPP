# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssuchane <ssuchane@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/18 17:14:52 by ssuchane          #+#    #+#              #
#    Updated: 2025/01/03 17:58:13 by ssuchane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp replace.cpp
OBJ = $(SRC:.cpp=.o)

TARGET = sed_is_for_losers

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f test
	rm -f test_replace

fclean: clean
	rm -f $(OBJ) $(TARGET)

re: fclean all

.PHONY: test clean fclean

test: all
	@echo "Creating test file..."
	@echo "test" > test
	@echo "Test file created with content: test"
	@echo "Running the program with arguments 'test es oooOooo'"
	@./sed_is_for_losers test es oooOooo
