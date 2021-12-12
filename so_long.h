#ifndef SO_LONG_H
#define SO_LONG_H
char	*get_next_line(int fd);
void	so_long (int fd);
#include <stdlib.h>
void	ft_check_wall (int fd, int lines);
void	others_check(int fd, int lines);
#define BUFFER_SIZE 10
#endif