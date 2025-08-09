NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes -Ilibft

# Main source files
SRC = \
    src/main.c \
    src/parse.c \
    src/parse_utils.c \
    src/normalize.c \
    src/duplicates.c \
    src/sorted.c \
    src/algorithm.c \
    src/small_sorts.c \
    src/quicksort_a.c \
    src/quicksort_b.c \
    src/swap.c \
    src/push.c \
    src/rotate.c \
    src/reverse_rotate.c

OBJ = $(SRC:.c=.o)

# Bonus source files (checker)
BONUS_SRC = \
    checker/checker.c \
    checker/checker_utils.c \
    checker/swap.c \
    checker/push.c \
    checker/rotate.c \
    checker/reverse_rotate.c

BONUS_OBJ = $(BONUS_SRC:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

clean:
	rm -f $(OBJ) $(BONUS_OBJ)
	$(MAKE) clean -C libft

fclean: clean
	rm -f $(NAME)
	rm -rf $(BONUS_NAME)
	$(MAKE) fclean -C libft

re: fclean all

.PHONY: all bonus clean fclean re