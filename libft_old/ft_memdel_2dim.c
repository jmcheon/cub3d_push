#include "libft.h"

void	ft_memdel_2dim(char **str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen_2dim((const char **)str);
	while (i < len)
	{
		free(str[i]);
		str[i++] = NULL;
	}
	free(str);
	str = NULL;
}
