#include "libft.h"

static size_t	ft_size(int n, int base)
{
	size_t	i;

	i = 1;
	while (n /= base)
		i++;
	return (i);
}

char	*ft_itoa_base(int nbr, char *base, char *flags)
{
	int		i;
	int		neg;
	int		base_size;
	char	*str;

	i = 0;
	base_size = ft_strlen(base);
	str = ft_strnew(ft_size(nbr, base_size) + 1);
	neg = 0;
	if (nbr < 0)
		neg = 1;
	if (nbr == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	while (nbr)
	{
		str[i++] = base[FT_ABS(nbr % base_size)];
		nbr = nbr / base_size;
	}
	if (neg)
		str[i++] = '-';
	else if (ft_strchr(flags, '+'))
		str[i++] = '+';
	else if (ft_strchr(flags, ' '))
		str[i++] = ' ';
	str[i] = '\0';
	return (ft_strrev(str));
}
