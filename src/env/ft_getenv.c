/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 14:30:00 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/10 14:30:27 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getenv(char **env, char *key)
{
	if (!env)
		return (NULL);
	while (*env)
	{
		/* ft_printf("%s\n", env[i]); */
		if (ft_strcmp(*env, key) == '=')
			return (*env + ft_strlen(key) + 1);
		env++;
	}
	return (NULL);
}
