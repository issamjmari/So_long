#include "so_long.h"
int map_check (int fd)
{
    char		*ret;
    int			i;
	static int	check;

	lines = 0;
	ret = get_next_line (fd);
	while (ret)
	{
		lines++;
		free (ret);
		ret = get_next_line (fd);
	}
}