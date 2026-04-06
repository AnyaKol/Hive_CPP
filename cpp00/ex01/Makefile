NAME = MyAwesomePhoneBook
CC = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = \
	PhoneBook.cpp \
	Contact.cpp \

OBJDIR = obj
OBJ = $(SRC:%.c=$(OBJDIR)/%.o)

# ------------  HEADER  ------------------------------------------------------ #
HEADER = \
	PhoneBook.h \
	Contact.h \

# ------------  RULES  ------------------------------------------------------- #
all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJDIR) $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ------------  EXTRA  ------------------------------------------------------- #
.SECONDARY: $(OBJDIR) $(OBJ)
.PHONY: all clean fclean re