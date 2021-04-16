#include "libft.h"
#include <stdio.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

int	main(int ac, char **av)
{
	int ret;
	int fd;
	char *str;
	char buf[BUFFER_SIZE + 1];

	fd = open(av[1], O_RDONLY):
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\n';
		str = ft_strjoin(str, buf);
		ft_bzero(buf);
	}	
	str = ft_strtrim(av[1], ":");
	printf("str = %s\n", str);

	return (0);
}
