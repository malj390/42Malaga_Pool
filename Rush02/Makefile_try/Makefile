# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = rush-02

# Source files (no duplicates!)
SRCS = main.c rush-02.c array_tools.c handling.c

HEADERS = FUNCTIONS_H

# Object files
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Link the final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile .c into .o
%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Cleanup rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

