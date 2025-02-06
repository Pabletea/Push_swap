NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LIBFT_DIR = ft_libft
PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRCS =	push_swap.c algorithm.c init_nodes_a.c init_nodes_b.c \
				instructions.c list_utils.c push.c rev_rotate.c \
				rotate.c sort_stack.c stack_utils.c swap.c utils.c \
				utils_2.c utils_3.c utils_4.c
OBJS = $(SRCS:.c=.o)



all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)

re: clean fclean all
