# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/21 09:53:34 by akolupae          #+#    #+#              #
#    Updated: 2026/05/21 10:34:30 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = easy_find
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++20
INKFLAGS = -I.

SRC = \
	main.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	easyfind.hpp \
	easyfind.tpp

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
