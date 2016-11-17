#include "libft.h"

void	ft_strsqueeze(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
		i++;
	ft_strcpy(str, str + 1);
}
