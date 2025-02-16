CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = rush-02

SRCS = main.c array_tools.c  FUNCTIONS_H  handling.c  main.c  numbers.dict  rush-02.c

HEADERS = FUNCTIONS.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
