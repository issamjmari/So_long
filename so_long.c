#include <mlx.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int next_frame (int key, t_img *i)
{
	int		width1;
	int		height1;
	if (key == 53)
		exit (1);
	return (0);
}

char	**get_all_lines (int *height, int fd)
{
	char	*ret;
	char	*temp;
	char	**all_lines;

	temp = NULL;
	ret = get_next_line (fd);
	while (ret)
	{
		(*height)++;
		if (ret[0] == '\n')
		{
			free (ret);
			printf ("Error\nEmpty line inside the map");
			exit (1);
		}
		temp = ft_strjoin (temp, ret);
		free (ret);
		ret = get_next_line (fd);
	}
	all_lines = ft_split(temp, '\n');
	free (temp);
	return (all_lines);
}

void	put_elems (char **all_lines, t_img i)
{
	y = 0;
	x = 0;
	while (all_lines[y])
	{
		while (all_lines[y][x])
		{
			if (all_lines[y][x] == '1')
				ft_draw_elem (x, y, "./wall11.xpm", i);
			else if (all_lines[y][x] == '0')
				ft_draw_elem (x, y, "./blueone.xpm", i);
			else if (all_lines[y][x] == 'C')
				ft_draw_elem (x, y, "./20.xpm", i);
			else if (all_lines[y][x] == 'E')
				ft_draw_elem (x, y, "./door.xpm", i);
			else if (all_lines[y][x] == 'P')
				ft_draw_elem (x, y, "./player.xpm", i);
			x++;
		}
		x = 0;
		y++;
	}
}
void so_long (int fd)
{
	int		width;
	int		height;
	char	**all_lines;
	t_img	i;

	height = 0;
	all_lines = get_all_lines (&height, fd);
	ft_check_wall (all_lines, height, &width);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, (width * 50), (height * 50), "so long");
	put_elems (all_lines, i);
	mlx_key_hook(i.win, next_frame, "something");
	mlx_loop (i.mlx);
}