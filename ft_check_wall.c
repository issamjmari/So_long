#include <fcntl.h>
#include "so_long.h"
#include "Libft/libft.h"

void completecase2(int len, char *ret)
{
	if (ret[0] != '1' || ret[len - 2] != '1')
	{
		printf ("Error\n%s", "Wall incomplete");
		exit (1);
	}
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

void	ft_check_wall (int fd)
{
	int		j;
	int		i;
	char	*ret;
	int		lines;
	int		len;

	lines = 0;
	i = 0;
	ret = get_next_line (fd);
	while (ret)
	{
		lines++;
		free (ret);
		ret = get_next_line (fd);
	}
	close (fd);
	fd = open ("test.ber", O_RDONLY);
	completecase1 (fd, i, lines, ret);
}