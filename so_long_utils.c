#include "so_long.h"

void	ft_draw_elem (int x, int y, void *path, t_img i)
{
	int height;
	int	width;

	i.img = mlx_xpm_file_to_image(i.mlx, path, &width, &height);
	mlx_put_image_to_window (i.mlx, i.win, i.img, x * 50, y * 50);
}