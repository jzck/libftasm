#include "libftprintf.h"

void	ft_fmt_simplify(t_fmt *fmt)
{
	char	hashtag;

	hashtag = '#';
	if (fmt->conversion == 'p')
	{
		fmt->conversion = 'x';
		if (!ft_strchr(fmt->flags, '#'))
			ft_strncat(fmt->flags, &hashtag, 1);
	}
	if (ft_strchr("DOUCS", fmt->conversion))
	{
		fmt->conversion += 32;
		ft_strcpy(fmt->modifier, "l");
	}
}
int		ft_fmt_validate_conversion(t_fmt *fmt)
{
	if (!ft_strchr(ALL_CONVERSIONS, fmt->conversion))
	{
		if (fmt->conversion != '%')
			ft_fmt_error_conv(fmt->conversion);
		return (1);
	}
	return (0);
}

void	ft_fmt_validate_flags(t_fmt *fmt)
{
	char	*flag_ptr;
	char	flag;
	int		i;

	i = 0;
	while (fmt->conversion != g_convs[i].id)
		i++;
	flag_ptr = fmt->flags;
	while (*flag_ptr)
	{
		flag = *flag_ptr;
		if (!ft_strchr(g_convs[i].allowed_flags, flag))
		{
			ft_fmt_error_flag_conv(flag, fmt->conversion);
			if (flag == '#')
				*flag_ptr = '.';
		}
		flag_ptr++;
	}
	if (ft_strchr(fmt->flags, '+') && (flag_ptr = ft_strchr(fmt->flags, ' ')))
	{
		ft_fmt_error_flag_flag(' ', '+');
		*flag_ptr = '.';
	}
	if (ft_strchr(fmt->flags, '-') && (flag_ptr = ft_strchr(fmt->flags, '0')))
	{
		ft_fmt_error_flag_flag('0', '-');
		*flag_ptr = '.';
	}
	if (fmt->precision && (flag_ptr = ft_strchr(fmt->flags, '0')))
		*flag_ptr = '.';
}

void	ft_fmt_validate_mod(t_fmt *fmt)
{
	if (fmt->conversion == 's' || fmt->conversion == 'c')
		if (fmt->modifier[0] && ft_strcmp(fmt->modifier, "l"))
			ft_fmt_error_mod_conv(fmt->modifier, fmt->conversion);
}
