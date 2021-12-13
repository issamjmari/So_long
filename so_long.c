#include <mlx.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int next_frame (int key, t_img *i)
{
	int		width1;
	int		height1;
	if (key == 5)
		exit (1);
	if (key == 53)
		ft_draw_elem (0, 0, ".blueone.xmp", i);
	return (0);
}

void	ft_draw_elem (int x, int y, void *path, t_img *i)
{
	int height;
	int	width;

	i->img = mlx_xpm_file_to_image(i->mlx, path, &width, &height);
	mlx_put_image_to_window (i->mlx, i->win, i->img, x * 50, y * 50);
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
void so_long (int fd)
{
	int		width;
	int		height;
	char	**all_lines;
	t_img	*i;

	height = 0;
	all_lines = get_all_lines (&height, fd);
	ft_check_wall (all_lines, height, &width);
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, (width * 50), (height * 50), "so long");
	mlx_key_hook(i->win, next_frame, "something");
	mlx_loop (i->mlx);
}