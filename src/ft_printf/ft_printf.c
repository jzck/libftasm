/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:27 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 16:20:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_conv	g_convs[] =
{
	{'d', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'i', "0- +", "0123456789", &ft_signed_conversion, NULL},
	{'u', "0-", "0123456789", &ft_unsigned_conversion, NULL},
	{'o', "#0-", "01234567", &ft_unsigned_conversion, &ft_pad_sharp_o},
	{'x', "#0-", "0123456789abcdef", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'X', "#0-", "0123456789ABCDEF", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'b', "#0-", "01", &ft_unsigned_conversion, &ft_pad_sharp_xb},
	{'s', "-", "", &ft_str_conversion, NULL},
	{'c', "-", "", &ft_char_conversion, NULL},
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
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!(fmt = ft_printf_parse(&str, ap1)))
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
