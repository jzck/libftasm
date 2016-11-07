/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_pad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:33:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:48:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

void	ft_pad_right(char *str, t_fmt *fmt)
{
	if (ft_strchr(fmt->flags, '#'))
		(fmt->conv.sharp_func)(str, fmt);
	while ((int)ft_strlen(str) < fmt->width)
		ft_strcat(str, " ");
}

void	ft_pad_left(char *str, t_fmt *fmt)
{
	char	buf[100];
	char	sign;

	sign = '\0';
	ft_bzero(buf, 100);
	if (str[0] == '-' || str[0] == '+' || str[0] == ' ')
	{
		sign = str[0];
		str++;
	}
	if (ft_strchr(fmt->flags, '0'))
	{
		while ((int)ft_strlen(str) < fmt->width - (sign ? 1 : 0))
		{
			ft_strcpy(buf, "0");
			ft_strcat(buf, str);
			ft_strcpy(str, buf);
		}
	}
	if (sign)
		str--;
	if (ft_strchr(fmt->flags, '#'))
		(fmt->conv.sharp_func)(str, fmt);
	while ((int)ft_strlen(str) < fmt->width)
	{
		ft_strcpy(buf, " ");
		ft_strcat(buf, str);
		ft_strcpy(str, buf);
	}
}
