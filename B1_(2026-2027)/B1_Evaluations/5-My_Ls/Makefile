CC = gcc 
NAME = my_ls 
CFLAGS = -Wall -Wextra -Werror -D_DEFAULT_SOURCE
SRCS = main.c my_ls.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):$(OBJS)
	$(CC)$(CFLAGS) $(OBJS) -o$(NAME) 

%.o: %.c header.h
	$(CC)$(CFLAGS) -c $< -o$@ 

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re