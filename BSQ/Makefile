# Compiler
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = bsq

# Source files (no duplicates!)
SRCS = analysis.c array_tools.c square_tools.c utils.c main.c

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

.PHONY: all clean fclean
