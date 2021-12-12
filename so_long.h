#ifndef SO_LONG_H
#define SO_LONG_H
char	*get_next_line(int fd);
void	so_long (int fd);
#include <stdlib.h>
void	ft_check_wall (char **all_lines, int len);
void	others_check(int fd, int lines);
char	*ft_strjoin(char *s1, char *s2);
char    **ft_split(char const *s, char c);
#define BUFFER_SIZE 10
#endif