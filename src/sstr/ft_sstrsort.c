#include "libft.h"

void	ft_sstrsort(char **list, int size, int (*cmp)())
{
	int		i;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		if ((*cmp)(list[i], list[i + 1]) > 0)
		{
			tmp = list[i];
			list[i] = list[i + 1];
			list[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
