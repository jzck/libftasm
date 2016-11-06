#include "ftprintf.h"

char	*ft_transform(t_fmt *fmt, va_list ap)
{
	char	*buf;
	char	*ret;
	int		i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	fmt->conv = g_convs[i];
	ret = (fmt->conv.converter)(fmt, ap);
	if (fmt->width > (int)ft_strlen(ret))
	{
		buf = ret;
		ret = (char *)malloc(sizeof(char) * (fmt->width + 5));
		ft_strcpy(ret, buf);
	}
	if (ft_strchr(fmt->flags, '-'))
		ft_pad_right(ret, fmt);
	else
		ft_pad_left(ret, fmt);
	return (ret);
}
