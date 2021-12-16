/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:58:42 by ijmari            #+#    #+#             */
/*   Updated: 2021/12/16 18:08:06 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bombandexit(char c, int *move, char **all_lines)
{
	int	len;

	len = 0;
	(void) all_lines;
	while (all_lines[len])
		len++;
	while (--len)
		free (all_lines[len]);
	free (all_lines);
	if (c == 'E')
	{
		printf ("\033[0;32mYOU WON IN %d MOVES", *move);
		exit(1);
	}
	if (c == 'Y')
	{
		printf ("\033[0;31mYOU'VE GET BOMBED SIR");
		exit (1);
	}
}

void	move_left(t_player *p, int *move)
{
	t_img	i;

	i = p->i;
	if (all_lines[p->posy][p->posx - 1] == 'Y')
		bombandexit ('Y', move, all_lines);
	if (all_lines[p->posy][p->posx - 1] == 'C'
	|| all_lines[p->posy][p->posx - 1] == 'P'
	|| all_lines[p->posy][p->posx - 1] == '0')
	{
		ft_draw_elem (p->posx - 1, p->posy, "./blueone.xpm", i);
		ft_draw_elem (p->posx - 1, p->posy, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		if (all_lines[p->posy][p->posx - 1] == 'C')
			p->coin--;
		all_lines[p->posy][p->posx - 1] = '0';
	}
	else if (all_lines[p->posy][p->posx - 1] == 'E' && p->coin <= 0)
		bombandexit ('Y', move, all_lines);
	else if (all_lines[p->posy][p->posx - 1] == '1'
	|| all_lines[p->posy][p->posx - 1] == 'E')
		return ;
	(*move)++;
	p->posx--;
}

void	move_right(t_player *p, int *move)
{
	t_img	i;

	i = p->i;
	if (all_lines[p->posy][p->posx + 1] == 'Y')
		bombandexit ('Y', move, all_lines);
	if (all_lines[p->posy][p->posx + 1] == 'C'
	|| all_lines[p->posy][p->posx + 1] == 'P'
	|| all_lines[p->posy][p->posx + 1] == '0')
	{
		ft_draw_elem (p->posx + 1, p->posy, "./blueone.xpm", i);
		ft_draw_elem (p->posx + 1, p->posy, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		if (all_lines[p->posy][p->posx + 1] == 'C')
			p->coin--;
		all_lines[p->posy][p->posx + 1] = '0';
	}
	else if (all_lines[p->posy][p->posx - 1] == 'E' && p->coin <= 0)
		bombandexit ('Y', move, all_lines);
	else if (all_lines[p->posy][p->posx + 1] == '1'
	|| all_lines[p->posy][p->posx + 1] == 'E')
		return ;
	(*move)++;
	p->posx++;
}

void	move_down(t_player *p, int *move)
{
	t_img	i;

	i = p->i;
	if (all_lines[p->posy + 1][p->posx] == 'Y')
		bombandexit ('Y', move, all_lines);
	if (all_lines[p->posy + 1][p->posx] == 'C'
	|| all_lines[p->posy + 1][p->posx] == 'P'
	|| all_lines[p->posy + 1][p->posx] == '0')
	{
		ft_draw_elem (p->posx, p->posy + 1, "./blueone.xpm", i);
		ft_draw_elem (p->posx, p->posy + 1, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		if (all_lines[p->posy + 1][p->posx] == 'C')
			p->coin--;
		all_lines[p->posy + 1][p->posx] = '0';
	}
	else if (all_lines[p->posy][p->posx - 1] == 'E' && p->coin <= 0)
		bombandexit ('Y', move, all_lines);
	else if (all_lines[p->posy + 1][p->posx] == '1' ||
	all_lines[p->posy + 1][p->posx] == 'E')
		return ;
	(*move)++;
	p->posy++;
}

void	move_up(t_player *p, int *move)
{
	t_img	i;

	i = p->i;
	if (all_lines[p->posy - 1][p->posx] == 'Y')
		bombandexit ('Y', move, all_lines);
	if (all_lines[p->posy - 1][p->posx] == 'C'
	|| all_lines[p->posy - 1][p->posx] == 'P'
	|| all_lines[p->posy - 1][p->posx] == '0')
	{
		ft_draw_elem (p->posx, p->posy - 1, "./blueone.xpm", i);
		ft_draw_elem (p->posx, p->posy - 1, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		if (all_lines[p->posy - 1][p->posx] == 'C')
			p->coin--;
		all_lines[p->posy - 1][p->posx] = '0';
	}
	else if (all_lines[p->posy][p->posx - 1] == 'E' && p->coin <= 0)
		bombandexit ('Y', move, all_lines);
	else if (all_lines[p->posy - 1][p->posx] == '1'
	|| all_lines[p->posy - 1][p->posx] == 'E')
		return ;
	(*move)++;
	p->posy--;
}