#include "libft.h"

void	ft_strlprint(char **strl, char sep)
{
	int		i;

	i = 0;
	while (strl[i])
		ft_printf("%s%c", strl[i], sep);
}
