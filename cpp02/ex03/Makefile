# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 17:45:11 by akolupae          #+#    #+#              #
#    Updated: 2026/04/15 21:39:24 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = BSP
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
INKFLAGS = -I.

SRC = \
	main.cpp \
	Fixed.cpp \
	Point.cpp \
	bsp.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	Fixed.hpp \
	Point.hpp

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
