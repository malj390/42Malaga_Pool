# Compiler
CC = gcc

# Compiler flags (warnings + required standards)
CFLAGS = -Wall -Wextra -Werror

# Executable name
NAME = rush-02

# Source files
SRCS = main.c rush-02.c array_tools.c handling.c handling2.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Default rule to compile the program
all: $(NAME)

# Rule to link object files into final executable
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile each .c file into an .o file
%.o: %.c functions.h
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove executable + object files
fclean: clean
	rm -f $(NAME)

# Recompile everything from scratch
re: fclean all

# Rule to avoid conflicts with files named "clean", "fclean", etc.
.PHONY: all clean fclean re

