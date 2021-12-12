#include "so_long.h"
#include <unistd.h>
#include <fcntl.h>
void so_long (int fd)
{
	char	*ret;
	char	*temp;
	char	**all_lines;
	int		len;

	temp = NULL;
	len = 0;
	ret = get_next_line (fd);
	while (ret)
	{
		len++;
		temp = ft_strjoin (temp, ret);
		free (ret);
		ret = get_next_line (fd);
	}
	all_lines = ft_split(temp, '\n');
	free (temp);
	ft_check_wall (all_lines, len);
}