SRC = ft_moves.c ft_split.c ft_itoa.c get_next_line.c so_long_utils.c get_next_line_utils.c so_long.c ft_check_wall.c ft_memcmp.c ft_strrchr.c main.c ft_strncmp.c
OBJ = $(SRC:.c=.o)
MLXFLAGS =  -lmlx -framework OpenGL -framework AppKit
CC = cc
CFLAGS = -Wall -Wextra -Werror
OUTPUT = so_long

all :
	$(CC) $(CFLAGS) $(SRC) $(MLXFLAGS) -o $(OUTPUT) -g
clean :
	rm -f $(OBJ)
fclean : clean
	rm -f $(OUTPUT)
re : fclean all