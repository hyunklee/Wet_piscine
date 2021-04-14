cc = gcc
CFLAGS = -Wall -Werror -Wextra

TARGET = libft.a

SRDIR = srcs
INCLUDE = -Iincludes

SRCS = $(SRDIR)/ft_putchar.c $(SRDIR)/ft_swap.c $(SRDIR)/ft_putstr.c $(SRDIR)/ft_strlen.c $(SRDIR)/ft_strcmp.c
OBJS = $(SRCS:.c=.o)
HDRS = ft.h

all : $(TARGET)

$(TARGET) : $(OBJS)
	ar rc $(TARGET) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean :
	rm $(OBJS)

fclean :
	rm $(TARGET) $(OBJS)

re : fclean all 
