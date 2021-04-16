#include "libft.h"

void	ft_memdel(char **str)
{
	if (*str)
	{
		free(*str);
		*str = NULL;
	}
}
