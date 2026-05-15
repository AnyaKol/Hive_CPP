# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 17:45:11 by akolupae          #+#    #+#              #
#    Updated: 2026/05/12 09:37:01 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = convert
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++17
INKFLAGS = -I.

SRC = \
	main.cpp \
	ScalarConverter.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	ScalarConverter.hpp

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	$(CPP) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ------------  EXTRA  ------------------------------------------------------- #
.SECONDARY: $(OBJDIR) $(OBJ)
.PHONY: all clean fclean re
