#include "libft.h"

size_t	ft_uilen(unsigned int n)
{
	size_t	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
