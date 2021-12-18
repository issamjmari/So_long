/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:22:43 by ijmari            #+#    #+#             */
/*   Updated: 2021/12/18 17:14:37 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_elem(int x, int y, void *path, t_img i)
{
	int	height;
	int	width;

	i.img = mlx_xpm_file_to_image(i.mlx, path, &width, &height);
	mlx_put_image_to_window (i.mlx, i.win, i.img, x * 50, y * 50);
}

t_player	webp(char **all_lines, t_img i, t_player test)
{
	if (all_lines[g_y][g_x] == '1')
		ft_draw_elem (g_x, g_y, "./wall.xpm", i);
	else if (all_lines[g_y][g_x] == '0')
		ft_draw_elem (g_x, g_y, "./blueone.xpm", i);
	else if (all_lines[g_y][g_x] == 'E')
		ft_draw_elem (g_x, g_y, "./door.xpm", i);
	else if (all_lines[g_y][g_x] == 'P')
	{
		ft_draw_elem (g_x, g_y, "./blueone.xpm", i);
		ft_draw_elem (g_x, g_y, "./player.xpm", i);
		test.posx = g_x;
		test.posy = g_y;
	}
	return (test);
}

t_player	put_elems(char **all_lines, t_player test, t_img i)
{
	g_y = 0;
	while (all_lines[g_y])
	{
		g_x = 0;
		while (all_lines[g_y][g_x])
		{
			if (all_lines[g_y][g_x] == 'C')
			{
				ft_draw_elem (g_x, g_y, "./blueone.xpm", i);
				ft_draw_elem (g_x, g_y, "./Ninja.xpm", i);
				test.coin++;
			}
			else if (all_lines[g_y][g_x] == 'Y')
			{
				ft_draw_elem (g_x, g_y, "./blueone.xpm", i);
				ft_draw_elem (g_x, g_y, "./bomb.xpm", i);
			}
			else
				test = webp (all_lines, i, test);
			g_x++;
		}
		g_y++;
	}
	return (test);
}

char	*needed(int fd, int *height, char *temp)
{
	char	*ret;

	ret = get_next_line (fd);
	if (!ret)
	{
		printf ("Error\nFile empty");
		exit (1);
	}
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
	return (temp);
}

char	**get_all_lines(int *height, int fd)
{
	char	*temp;
	char	**all_lines;

	temp = NULL;
	temp = needed (fd, height, temp);
	all_lines = ft_split(temp, '\n');
	free (temp);
	return (all_lines);
}
