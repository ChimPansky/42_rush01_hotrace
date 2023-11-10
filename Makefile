NAME = hotrace
CC = cc
CFLAGS = -Wall -Werror -Wextra -O3 -pg

#SOURCE_DIR = src/
#INCLUDE_DIR = include/
#LIBFT_DIR = libft/
#LIBFT_NAME = libft.a
HEADER = hotrace.h

#Colors
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SRC_FILES = hotrace \
	get_next_line get_next_line_utils \
	ft_strdup ft_strdup_nonl ft_strlen ft_strlcpy ft_calloc \
	ft_putendl_fd ft_putchar_fd ft_putstr_fd ft_putstr_fd_nonl \
	ft_putsizet_fd ft_lstadd_front hotrace_hashing

SRC = $(addsuffix .c, $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) -g -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created!$(DEF_COLOR)"

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
