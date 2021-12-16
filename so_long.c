/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:09:56 by ijmari            #+#    #+#             */
/*   Updated: 2021/12/16 18:10:31 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>

int	next_frame(int key, t_player *p)
{
	static int	move;
	t_img		i;
	char		*move_s;

	i = p->i;
	if (key == 53)
		exit (1);
	if (key == 13 || key == 126)
		move_up (p, &move);
	if (key == 0 || key == 123)
		move_left (p, &move);
	if (key == 1 || key == 125)
		move_down (p, &move);
	if (key == 2 || key == 124)
		move_right (p, &move);
	ft_draw_elem (0, 0, "./wall.xpm", i);
	move_s = ft_itoa(move);
	mlx_string_put(i.mlx, i.win, 10, 10, 0x000000, move_s);
	free (move_s);
	system ("leaks so_long");
	return (0);
}

int	closee(void)
{
	exit (1);
}

void	so_long(int fd)
{
	int			width;
	int			height;
	t_img		i;
	t_player	p;
	t_player	test;

	height = 0;
	test.coin = 0;
	all_lines = get_all_lines (&height, fd);
	ft_check_wall (all_lines, height, &width);
	i.mlx = mlx_init();
	i.win = mlx_new_window(i.mlx, (width * 50), (height * 50), "so long");
	p = put_elems (all_lines, test, i);
	p.i = i;
	mlx_key_hook(i.win, next_frame, &p);
	mlx_hook(i.win, 17, 0, closee, NULL);
	mlx_loop (i.mlx);
}

int	main(int ac, char **av)
{
	int	fd;

	fd = open (av[1], O_RDONLY);
	if (fd == -1 || ac > 2)
	{
		printf ("Error\nMap not found");
		exit (1);
	}
	so_long (fd);
	close (fd);
}
