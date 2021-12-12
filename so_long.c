#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
void so_long (int fd)
{
	char	*ret;
	int		lines;
	int		i;
	int		j;

	ret = get_next_line (fd);
	lines = 0;
	while (ret)
	{
		lines++;
		free (ret);
		ret = get_next_line (fd);
	}
	close (fd);
	fd = open ("test.ber", O_RDONLY);
	ft_check_wall(fd, lines);
}