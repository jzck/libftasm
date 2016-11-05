/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_removeif.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:30 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 13:07:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_removeif(t_list **alst, void *data_ref, int (*cmp)())
{
	t_list	*tmp;
	t_list	**indirect;

	tmp = NULL;
	indirect = alst;
	while (*indirect)
	{
		if ((*cmp)((*indirect)->content, data_ref) == 0)
		{
			tmp = (*indirect);
			tmp->next = NULL;
			(*indirect) = (*indirect)->next;
			return (tmp);
		}
		indirect = &(*indirect)->next;
	}
	return (NULL);
}
