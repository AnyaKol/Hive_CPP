# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akolupae <akolupae@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 17:44:29 by akolupae          #+#    #+#              #
#    Updated: 2026/04/08 17:44:31 by akolupae         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++11

SRC = \
	megaphone.cpp \

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

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
