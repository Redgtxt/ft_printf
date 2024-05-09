CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putchar.c ft_putstr.c printbase.c ft_putptr_base.c 
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
CREATE = ar -rc
REMOVE = rm -f

all: $(NAME)

$(NAME): 	$(OBJS) 
	$(CREATE) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	$(REMOVE)	$(NAME)

re: fclean all