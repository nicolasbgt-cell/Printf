NAME    = libftprintf.a
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
SOURCES = ft_printf.c ft_printf_hex.c ft_printf_nbr.c ft_printf_utils.c
OBJS    = $(SOURCES:%.c=%.o)

all: libft/libft.a $(NAME)

libft/libft.a:
	make -C libft

$(NAME): $(OBJS)
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all 
