NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I.

SRC = ft_isdigit.c ft_isspace.c ft_strlen.c ft_io.c ft_strdup.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re