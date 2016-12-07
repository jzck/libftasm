/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 14:25:45 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 16:29:08 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstrdup(char **list)
{
	int		i;
	int		size;
	char	**cpy;

	i = 0;
	size = 0;
	DG("sstrdup call now");
	while (list[size])
		size++;
	cpy = (char **)malloc(sizeof(char *) * (size + 1));
	while (*list)
	{
		cpy[i++] = ft_strdup(*list);
		list++;
	}
	DG("sstrdup i=%i, size=%i (should be equal)", i, size);
	cpy[i] = NULL;
	return (cpy);
}
