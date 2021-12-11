#include <mlx.h>
#include <fcntl.h>
#include "so_long.h"

int	main(void)
{
	int fd = open ("test.ber", O_RDONLY);
	int fd1 = open ("test1,ber", O_RDONLY);
	so_long (fd);
}
