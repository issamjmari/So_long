#include "so_long.h"

void	ft_draw_elem (int x, int y, void *path, t_img i)
{
	int height;
	int	width;

	i.img = mlx_xpm_file_to_image(i.mlx, path, &width, &height);
	mlx_put_image_to_window (i.mlx, i.win, i.img, x * 50, y * 50);
}
void move_left (t_player *p)
{
	t_img		i;

	i = p->i;
	if (all_lines[p->posy][p->posx - 1] == 'C' || all_lines[p->posy][p->posx - 1] == 'P'
	|| all_lines[p->posy][p->posx - 1] == '0')
	{
		ft_draw_elem (p->posx - 1, p->posy, "./blueone.xpm", i);
		ft_draw_elem (p->posx - 1, p->posy, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		p->coin--;
	}
	else if (all_lines[p->posy][p->posx - 1] == 'E' && p->coin <= 0)
	{
		printf ("\033[0;32m");
		printf ("YOU WON");
		exit(1);
	}
	else if (all_lines[p->posy][p->posx - 1] == '1')
		return ;
	p->posx--;
}
void move_right (t_player *p)
{
	t_img		i;

	i = p->i;
	if (all_lines[p->posy][p->posx + 1] == 'C' || all_lines[p->posy][p->posx + 1] == 'P'
	|| all_lines[p->posy][p->posx + 1] == '0')
	{
		ft_draw_elem (p->posx + 1, p->posy, "./blueone.xpm", i);
		ft_draw_elem (p->posx + 1, p->posy, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		p->coin--;
	}
	else if (all_lines[p->posy][p->posx + 1] == 'E' && p->coin <= 0)
	{
		printf ("\033[0;32m");
		printf ("YOU WON");
		exit(1);
	}
	else if (all_lines[p->posy][p->posx + 1] == '1')
		return ;
	p->posx++;
}
void move_down (t_player *p)
{
	t_img		i;

	i = p->i;
	if (all_lines[p->posy + 1][p->posx] == 'C' || all_lines[p->posy + 1][p->posx] == 'P'
	|| all_lines[p->posy + 1][p->posx] == '0')
	{
		ft_draw_elem (p->posx, p->posy + 1, "./blueone.xpm", i);
		ft_draw_elem (p->posx, p->posy + 1, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		p->coin--;
	}
	else if (all_lines[p->posy + 1][p->posx] == 'E' && p->coin <= 0)
	{
		printf ("\033[0;32m");
		printf ("YOU WON");
		exit(1);
	}
	else if (all_lines[p->posy + 1][p->posx] == '1')
		return ;
	p->posy++;
}

void move_up (t_player *p)
{
	t_img		i;

	i = p->i;
	if (all_lines[p->posy - 1][p->posx] == 'C' || all_lines[p->posy - 1][p->posx] == 'P'
	|| all_lines[p->posy - 1][p->posx] == '0')
	{
		ft_draw_elem (p->posx, p->posy - 1, "./blueone.xpm", i);
		ft_draw_elem (p->posx, p->posy - 1, "./player.xpm", i);
		ft_draw_elem (p->posx, p->posy, "./blueone.xpm", i);
		p->coin--;
	}
	else if (all_lines[p->posy - 1][p->posx] == 'E' && p->coin <= 0)
	{
		printf ("\033[0;32m");
		printf ("YOU WON");
		exit(1);
	}
	else if (all_lines[p->posy - 1][p->posx] == '1'
	|| all_lines[p->posy - 1][p->posx] == 'E')
		return ;
	p->posy--;
}