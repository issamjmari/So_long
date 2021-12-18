/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ijmari <ijmari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 17:48:35 by ijmari            #+#    #+#             */
/*   Updated: 2021/12/18 12:05:04 by ijmari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# define BUFFER_SIZE 10

typedef struct s_img
{
	char	*relative_path;
	int		img_width;
	int		img_height;
	void	*mlx;
	void	*img;
	void	*win;
}	t_img;

typedef struct s_player
{
	int		posx;
	int		posy;
	int		coin;
	t_img	i;
}	t_player;

typedef struct s_wall
{
	int		posx;
	int		posy;
}	t_wall;

int			g_x;
int			g_y;
char		**g_all_lines;
int	ft_strncmp(char *s1, char *s2, unsigned int n);
size_t		ft_strlen(const char *s);
char    	*ft_strrchr(char *s, int c);
int			ft_memcmp(void *s1, void *s2, size_t n);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_itoa(int n);
void		ft_check_wall(char **all_lines, int len, int *width);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		others_check(int fd, int lines);
char		**ft_split(char const *s, char c);
char		**get_all_lines(int *len, int fd);
char		*get_next_line(int fd);
void		so_long(int fd);
void		ft_draw_elem(int x, int y, void *path, t_img i);
t_player	put_elems(char **all_lines, t_player test, t_img i);
void		move_up(t_player *p, int *move);
void		move_down(t_player *p, int *move);
void		move_left(t_player *p, int *move);
void		move_right(t_player *p, int *move);
#endif