NAME = libftprintf.a
EXE = test_program

CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_printf_utils.c \
	ft_printf_char.c \
	ft_printf_str.c \
	ft_printf_int.c \
	ft_printf_hex.c \
	ft_printf_pointer.c \
	ft_printf_unsigned_int.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

# Regla para compilar el ejecutable
$(EXE): $(NAME) main.o
	$(CC) $(FLAGS) -o $(EXE) main.o -L. -lftprintf

main.o: main.c
	$(CC) $(FLAGS) -c main.c

clean:
	rm -f $(OBJ) main.o

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

.PHONY: all clean fclean re
