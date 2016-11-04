/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:12 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:47:22 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_delif(
		t_list **alst,
		void *data_ref, int (*cmp)(),
		void (*del)(void *, size_t))
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = NULL;
	current = *alst;
	tmp = NULL;
	while (current)
	{
		if ((*cmp)(current->content, data_ref) == 0)
		{
			if (current == *alst)
				*alst = current->next;
			else
				last->next = current->next;
			tmp = current;
			current = current->next;
			ft_lstdelone(&tmp, del);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}
