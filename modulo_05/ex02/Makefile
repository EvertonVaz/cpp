# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egeraldo <egeraldo@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/18 14:27:47 by egeraldo          #+#    #+#              #
#    Updated: 2024/07/22 11:51:20 by egeraldo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = office
FLAGS = -Wall -Werror -Wextra -g3 -std=c++98
CC = c++

# Colors Definition
BLUE = "\033[34;1m"
GREEN = "\033[32;1m"
RED = "\033[31;1m"
CYAN = "\033[36;1;3;208m"
WHITE = "\033[37;1;4m"
COLOR_LIMITER = "\033[0m"

# Paths for libraries
BIN_PATH = ./bin/
MANDATORY_SOURCES_PATH = ./
CLASSES = ./classes/

SRC = \
	main.cpp Bureaucrat.cpp AForm.cpp \
	ShrubberyCreationForm.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp

OBJECTS = $(addprefix $(BIN_PATH), $(SRC:%.cpp=%.o))

all: $(BIN_PATH) $(NAME)

$(BIN_PATH)%.o: $(MANDATORY_SOURCES_PATH)%.cpp
	@echo $(BLUE)[Compiling Megaphone]$(COLOR_LIMITER) $(WHITE)$(notdir $(<))$(COLOR_LIMITER)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(CLASSES)
	@echo " "

$(NAME): $(OBJECTS)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@echo $(CYAN)"|      executable was created successfully!!     |"$(COLOR_LIMITER)
	@echo $(CYAN)"--------------------------------------------------"$(COLOR_LIMITER)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)
	@echo " "

$(BIN_PATH):
	@mkdir -p $(BIN_PATH)

clean:
	@echo $(RED)[Removing Objects]$(COLOR_LIMITER)
	@rm -rf $(BIN_PATH)

fclean: clean
	@echo $(RED)[Removing $(NAME) executable]$(COLOR_LIMITER)
	@rm -rf $(NAME)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re bonus