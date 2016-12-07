/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 18:03:58 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/07 17:39:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_sstradd(char **sstr, char *new)
{
	int		i;
	int		size;
	char	**newlist;

	i = 0;
	size = 0;
	if (sstr)
		while (sstr[size])
			size++;
	if (!(newlist = (char **)ft_memalloc(sizeof(char *) * (size + 2))))
		return (NULL);
	if (sstr)
		ft_memcpy(newlist, sstr, sizeof(char*) * size);
	newlist[size++] = ft_strdup(new);
	newlist[size] = NULL;
	free(sstr);
	return (newlist);
}
