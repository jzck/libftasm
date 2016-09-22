#include "libft.h"

static size_t	ft_size(unsigned int n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char	*ft_uitoa_base(unsigned int nbr, char *base)
{
	int		i;
	int		base_size;
	char	*str;

	/* printf("converting %llu to base %s\n", nbr, base); */
	/* fflush(stdout); */
	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_size(nbr, base_size) + 1);
	if (nbr == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (nbr)
	{
		str[i++] = base[nbr % base_size];
		nbr = nbr / base_size;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
