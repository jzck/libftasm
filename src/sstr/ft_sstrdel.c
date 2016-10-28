#include "libft.h"

void	ft_sstrdel(char **sstr, int index)
{
	int		i;

	i = index;
	while (sstr[i])
	{
		sstr[i] = sstr[i + 1];
		i++;
	}
}
