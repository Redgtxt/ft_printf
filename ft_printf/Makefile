CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c ft_putchar.c ft_putstr.c functions.c
OBJS = $(SRCS:.c=.o)
TARGET = ft_printf

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

run: $(TARGET)
	./$(TARGET)

re: fclean all