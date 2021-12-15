/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:22:43 by ijmari            #+#    #+#             */
/*   Updated: 2021/12/15 20:42:38 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elem (int x, int y, void *path, t_img i)
{
	int	height;
	int	width;

	i.img = mlx_xpm_file_to_image(i.mlx, path, &width, &height);
	mlx_put_image_to_window (i.mlx, i.win, i.img, x * 50, y * 50);
}

void	wex (char **all_lines, t_img i)
{
	if (all_lines[y][x] == '1')
		ft_draw_elem (x, y, "./wall.xpm", i);
	else if (all_lines[y][x] == '0')
		ft_draw_elem (x, y, "./blueone.xpm", i);
	else if (all_lines[y][x] == 'E')
		ft_draw_elem (x, y, "./door.xpm", i);
}

t_player	put_elems (char **all_lines, t_player test, t_img i)
{
	y = 0;
	while (all_lines[y])
	{
		x = 0;
		while (all_lines[y][x])
		{
			if (all_lines[y][x] == 'C')
			{
				ft_draw_elem (x, y, "./blueone.xpm", i);
				ft_draw_elem (x, y, "./Ninja.xpm", i);
				test.coin++;
			}
			else if (all_lines[y][x] == 'P')
			{
				ft_draw_elem (x, y, "./blueone.xpm", i);
				ft_draw_elem (x, y, "./player.xpm", i);
				test.posx = x;
				test.posy = y;
			}
			else
				wex (all_lines, i);
			x++;
		}
		y++;
	}
	return (test);
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
