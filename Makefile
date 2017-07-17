# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kbamping <kbamping@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/17 12:35:16 by kbamping          #+#    #+#              #
#    Updated: 2017/07/17 12:39:44 by kbamping         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-- PROGRAM --#
PROG		= avm
SRC			= ./src
SRCS		= $(SRC)/main.cpp
OBJS		= $(SRCS:%.cpp=%.o)

#-- Compiler, libs, flags
INCLUDES	= -I ./include
WFLAGS		= -Wall -Wextra -Werror -g3 -std=c++11
CXX			= clang++
CXXFLAGS	= $(WFLAGS) $(INCLUDES)

.PHONY: clean fclean re run

#-- RULES --#
all: $(PROG)

#-- Core Program
$(SRC)/%.o : $(SRC)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "\033[01;36m$(PROG) \t\t-- \033[00;32m>>\033[0m $@"

$(PROG): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -ldl -o $(PROG)
	@echo "\033[01;36m$(PROG) \t\t-- \033[00;32mCOMPILED\033[0m\n"

#-- General rules
clean:
	@rm -f $(OBJS)
	@echo "\033[01;36m$(PROG) \t\t-- \033[00;32mREMOVED OBJECT FILES\033[0m"

fclean: clean
	@rm -f $(PROG)
	@echo "\033[01;36m$(PROG) \t\t-- \033[00;32mREMOVED EXECUTABLE\033[0m\n"

re: fclean all

run:
	@rm -f $(PROG)
	@echo "\033[01;36m$(PROG) \t\t-- \033[00;32mREMOVED EXECUTABLE\033[0m\n"
	@$(MAKE) -s all
	./$(PROG) text.txt

run_valgrind:
	valgrind --track-origins=yes --leak-check=full --show-reachable=yes ./$(PROG) text.txt