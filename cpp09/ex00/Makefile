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

NAME = btc
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++17
INKFLAGS = -I.

SRC = \
	main.cpp \
	BitcoinExchange.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	BitcoinExchange.hpp

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	$(CPP) $(CPPFLAGS) $(INCFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ------------  EXTRA  ------------------------------------------------------- #
.SECONDARY: $(OBJDIR) $(OBJ)
.PHONY: all clean fclean re
