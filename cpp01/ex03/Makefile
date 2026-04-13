# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 17:45:11 by akolupae          #+#    #+#              #
#    Updated: 2026/04/13 19:37:53 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Unnecessary_violence
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98
INKFLAGS = -I.

SRC = \
	main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	Weapon.hpp \
	HumanA.hpp \
	HumanB.hpp

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
