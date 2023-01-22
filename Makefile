CC = cc
CFLAGS = -Wall -Werror -Wextra
CFILES = libft/ft_strlen.c libft/ft_strncmp.c \
		libft/ft_free.c libft/ft_strjoin.c libft/ft_split.c \
		libft/ft_putstr_fd.c libft/ft_putendl_fd.c \
		src/help_pipex.c \
		src/get_path.c \
		src/args_execve.c \
		src/ft_childs.c \
		src/pipex.c

OBJ = $(CFILES:.c=.o)
NAME = pipex

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
