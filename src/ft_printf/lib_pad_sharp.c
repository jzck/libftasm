#include "ftprintf.h"

void	ft_pad_sharp_o(char *str)
{
	char	buf[100];

	if (str[0] != '0')
	{
		ft_strcpy(buf, "0");
		ft_strcat(buf, str);
		ft_strcpy(str, buf);
	}
}

void	ft_pad_sharp_x(char *str, t_fmt *fmt)
{
	char	buf[100];

	if (str[1] == '0')
		str[1] = fmt->conversion;
	else
	{
		ft_strcpy(buf, "0");
		if (str[0] == '0')
			str[0] = fmt->conversion;
		else
			ft_strcat(buf, &fmt->conversion);
		ft_strcat(buf, str);
		ft_strcpy(str, buf);
	}
}

void	ft_pad_sharp(char *str, t_fmt *fmt)
{
	if (ft_strchr(fmt->flags, '#'))
	{
		if (fmt->conversion == 'x' || fmt->conversion == 'X')
			ft_pad_sharp_x(str, fmt);
		if (fmt->conversion == 'o')
			ft_pad_sharp_o(str);
	}
}
