#include "libft.h"

void	ft_sstrprint(char **list, char sep)
{
	int		i;

	i = 0;
	while (list[i])
		ft_printf("%s%c", list[i++], sep);
}
