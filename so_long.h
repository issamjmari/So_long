#ifndef SO_LONG_H
#define SO_LONG_H
char	*get_next_line(int fd);
void	so_long (int fd);
#include <stdlib.h>
#include <stdio.h>
void	ft_check_wall (char **all_lines, int len, int *width);
void	others_check(int fd, int lines);
char	*ft_strjoin(char *s1, char *s2);
char    **ft_split(char const *s, char c);
char	**get_all_lines (int *len, int fd);
void	ft_draw_elem (int x, int y, void *path, t_img *i);
typedef struct s_img
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*img;
	void	*win;
}	t_img;
#define BUFFER_SIZE 10
#endif