NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
SRC_DIR = .
MOVES_DIR = moves
SORT_DIR = sort
SRC = main.c parser.c parser_helper.c \
	$(SORT_DIR)/main_sort.c \
	$(SORT_DIR)/stack_operations.c \
	$(SORT_DIR)/sort_utilities.c \
	$(SORT_DIR)/sort_small.c \
	$(SORT_DIR)/sort_five_elements.c \
	$(SORT_DIR)/chunk_operations.c \
	$(SORT_DIR)/chunk_sorting.c \
	$(MOVES_DIR)/moves_rotate.c \
	$(MOVES_DIR)/moves_push_swap.c \
	$(MOVES_DIR)/moves_group.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 