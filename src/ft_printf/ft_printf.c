#include "libftprintf.h"

t_conv	g_convs[] =
{
	{'d', "0123456789", ft_signed_conversion, "0- +"},
	{'i', "0123456789", ft_signed_conversion, "0- +"},
	{'u', "0123456789", ft_unsigned_conversion, "#0-"},
	{'o', "01234567", ft_unsigned_conversion, "#0-"},
	{'x', "0123456789abcdef", ft_unsigned_conversion, "#0-"},
	{'X', "0123456789ABCDEF", ft_unsigned_conversion, "#0-"},
	{'s', "", ft_str_conversion, "-"},
	{'c', "", ft_char_conversion, "-"},
};

int	ft_printf(const char *format, ...)
{
	va_list	ap1;
	char	*str;
	char	final[1000];
	t_fmt	*fmt;

	va_start(ap1, format);
	str = ft_strdup(format);
	ft_bzero(final, 1000);
	/* ft_putendl(format); */
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!(fmt = ft_parse(&str)))
				return (1);
			if (!fmt->valid)
				ft_strncat(final, &fmt->conversion, 1);
			else
				ft_strcat(final, ft_transform(fmt, ap1));
		}
		else
			ft_strncat(final, str++, 1);
	}
	ft_putstr(final);
	return (0);
}
