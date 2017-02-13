#include "libft.h"

char	*ft_strtok(char *s, const char *delim)
{
	static char	*lasts;
	int			ch;

	if (s == 0)
		s = lasts;
	do {
		if ((ch = *s++) == 0)
			return (0);
	} while (ft_strchr(delim, ch));
	--s;
	lasts = s + ft_strcspn(s, delim);
	if (*lasts != 0)
		*lasts++ = 0;
	return (s);
}
