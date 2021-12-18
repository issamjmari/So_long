#include "so_long.h"
#include <fcntl.h>
int	main(int ac, char **av)
{
	int	fd;

	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
	{
		printf ("Error\nMap extension is not .ber");
		exit (1);
	}
	fd = open (av[1], O_RDONLY);
	if (fd == -1 || ac > 2)
	{
		printf ("Error\nMap not found");
		exit (1);
	}
	so_long (fd);
	close (fd);
}
