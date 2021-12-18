SRC = ft_moves.c ft_split.c ft_itoa.c get_next_line.c so_long_utils.c get_next_line_utils.c so_long.c ft_check_wall.c ft_memcmp.c ft_strrchr.c ft_strncmp.c
CFLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME = so_long

all : $(NAME)
$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $(NAME)
clean :

fclean :
	rm -f $(NAME)
re : fclean all