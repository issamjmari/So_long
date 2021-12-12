#include <fcntl.h>
#include "so_long.h"
#include "Libft/libft.h"

void	check_cases (int coin, int ex, int player)
{
	if (coin == 0)
	{
		printf ("There must be at least one collectible");
		exit (1);
	}
	if (ex == 0)
	{
		printf ("There must be at least one exit");
		exit (1);
	}
	if (player > 1)
	{
		printf ("There must be one single player");
		exit (1);
	}
}

void	count_cases (int len, char *ret, int i)
{
	static int	coin;
	static int	ex;
	static int	player;

	while (i < (len - 1))
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
			printf ("Error\n%s", "Unknown map char");
			exit (1);
		}
		i++;
	}
	check_cases (coin, ex, player);
}
void completecase2(int len, char *ret)
{
	int i;

	i = 1;
	if (ret[0] != '1' || ret[len - 2] != '1')
	{
		printf ("Error\n%s", "Wall incomplete");
		exit (1);
	}
	count_cases (len, ret, i);
}
void	completecase1 (int fd, int i, int lines, char *ret)
{
	int	j;
	int len;
	while (i < lines)
	{
		j = 0;
		ret = get_next_line (fd);
		len = ft_strlen (ret);
		if (i == 0 || i == lines - 1)
		{
			while (ret[j] == '1')
				j++;
			if (ret[j] != '\n' && ret[j] != '\0')
			{
				printf ("Error\n%s", "Wall incomplete");
				exit (1);
			}
		}
		else
			completecase2(len, ret);
		i++;
	}
}

void	ft_check_wall (int fd, int lines)
{
	int		j;
	int		i;
	char	*ret;
	int		len;

	i = 0;
	completecase1 (fd, i, lines, ret);
}