#include "libft.h"

size_t	ft_strcspn(char *s, const char *delim)
{
	char	*str;

	str = s;
	while(*str)
		if(strchr(delim,*str))
			return (str - s);
		else
			str++;
	return (str - s);
}
