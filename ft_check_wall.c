#include <fcntl.h>
#include "so_long.h"
#include "Libft/libft.h"

void	check_cases (int coin, int ex, int player)
{
	if (coin == 0)
	{
		printf ("Error\nThere must be at least one collectible");
		exit (1);
	}
	if (ex == 0)
	{
		printf ("Error\nThere must be at least one exit");
		exit (1);
	}
	if (player > 1 || player == 0)
	{
		printf ("Error\nThere must be one single player");
		exit (1);
	}
}

void	count_cases (int arr_len, char *ret, int darr_len, int i)
{
	static int	line_num;
	static int	coin;
	static int	ex;
	static int	player;

	while (i < arr_len - 1)
	{
		if (ret[i] == 'C')
			coin++;
		else if (ret[i] == 'E')
			ex++;
		else if (ret[i] == 'P')
			player++;
		else if (ret[i] != 'C' && ret[i] != 'E' && ret[i] != '0'
		&& ret[i] != 'P' && ret[i] != '1')
		{
			printf ("Error\nUnknown char in map");
			exit (1);
		}
		i++;
	}
	if (line_num == darr_len - 2)
		check_cases (coin, ex, player);
	line_num++;
}

void ft_checkbottom(char *curr, int darr_len, int *width)
{
	int 		i;
	static int	arr_len;
	static int	stock_len;

	i = 0;
	if (arr_len == 0)
	{
		arr_len = ft_strlen (curr);
		stock_len = arr_len;
		(*width) = arr_len;
	}
	else
		arr_len = ft_strlen (curr);
	if (stock_len != arr_len)
	{
		printf ("Error\nMap is not rectangular");
		exit (1);
	}
	if (curr[0] != '1' || curr[arr_len - 1] != '1')
	{
		printf ("Error\n%s", "Wall incomplete");
		exit (1);
	}
	count_cases (arr_len, curr, darr_len, i);
}

void	ft_check_fll (char *first, char *last)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (first[i])
		i++;
	while (last[j])
		j++;
	if (i != j)
	{
		printf ("Error\nMap is not rectangular");
		exit (1);
	}
	i = 0;
	while (first[i] == '1' && last[i] == '1')
		i++;
	if ((first[i] != '\n' && first[i] != '\0') 
	|| (last[i] != '\n' && last[i] != '\0'))
	{
		printf ("Error\nWall Incomplete");
		exit (1);
	}
}

void	ft_check_wall (char **all_lines, int darr_len, int *width)
{
	int		i;

	i = 1;
	ft_check_fll (all_lines[0], all_lines[darr_len - 1]);
	while (i < darr_len)
	{
		ft_checkbottom (all_lines[i], darr_len, width);
		i++;
	}
	while (--darr_len)
		free(all_lines[darr_len]);
	free(all_lines);
}