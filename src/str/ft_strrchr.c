#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*a;
	int		i;

	a = (char *)s;
	i = ft_strlen(a);
	while (i >= 0)
	{
		if (a[i] == (char)c)
			return (a + i);
		i--;
	}
	return (NULL);
}
