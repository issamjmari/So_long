#include <mlx.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int next_frame(int key, t_player *p)
{
	static int	move;
	t_img		i;

	i = p->i;
	if (key == 13 || key == 126)
	{
		move_up (p);
		move++;
	}
	if (key == 0 || key == 123)
	{
		move_left (p);
		move++;
	}
	if (key == 1 || key == 125)
	{
		move_down (p);
		move++;
	}
	if (key == 2 || key == 124)
	{
		move_right (p);
		move++;
	}
	mlx_string_put(i.mlx, i.win, 10, 10, 0xFF8000, ft_itoa(move));
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

t_player	put_elems (char **all_lines, t_img i)
{
	t_player	test;
	y = 0;
	test.coin = 0;
	while (all_lines[y])
	{
		x = 0;
		while (all_lines[y][x])
		{
			if (all_lines[y][x] == '1')
				ft_draw_elem (x, y, "./wall.xpm", i);
			else if (all_lines[y][x] == '0')
				ft_draw_elem (x, y, "./blueone.xpm", i);
			else if (all_lines[y][x] == 'C')
			{
				ft_draw_elem (x, y, "./20.xpm", i);
				test.coin++;
			}
			else if (all_lines[y][x] == 'E')
				ft_draw_elem (x, y, "./door.xpm", i);
			else if (all_lines[y][x] == 'P')
			{
				ft_draw_elem (x, y, "./player.xpm", i);
				test.posx = x;
				test.posy = y;
			}
			x++;
		}
		y++;
	}
	return (test);
}

void so_long (int fd)
{
	int			width;
	int			height;
	t_img		i;
	t_player	p;

	height = 0;
	all_lines = get_all_lines (&height, fd);
	ft_check_wall (all_lines, height, &width);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, (width * 50), (height * 50), "so long");
	p = put_elems (all_lines, i);
	p.i = i;
	mlx_key_hook(i.win, next_frame, &p);
	mlx_loop (i.mlx);
}