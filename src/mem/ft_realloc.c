/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:37:53 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/11 17:41:30 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *data, int size)
{
	void	*new;

	ft_printf("realloc befor: '%s'\n", data);
	new = ft_memalloc(size);
	ft_memcpy(new, data, ft_strlen(data));
	ft_memdel(&data);
	ft_printf("realloc after: '%s'\n", new);
	return (new);
}
