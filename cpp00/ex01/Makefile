NAME = MyAwesomePhoneBook
CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
	PhoneBook.cpp \
	Contact.cpp \

OBJDIR = obj
OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	PhoneBook.hpp \
	Contact.hpp \

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ) $(HEADER)
	$(CPP) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ------------  EXTRA  ------------------------------------------------------- #
.SECONDARY: $(OBJDIR) $(OBJ)
.PHONY: all clean fclean re
