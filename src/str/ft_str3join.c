#include "libft.h"

char	*ft_str3join(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	int		size;

	size = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	join = ft_strnew(size + 1);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	ft_strcat(join, s3);
	return (join);
}
