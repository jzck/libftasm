#include "libft.h"

char	**ft_sstrdup(char **list)
{
	int		i;
	int		size;
	char	**cpy;

	i = 0;
	size = 0;
	while (list[size])
		size++;
	cpy = (char **)malloc(sizeof(char *) * (size + 1));
	while (*list)
	{
		cpy[i++] = ft_strdup(*list);
		list++;
	}
	return (cpy);
}
