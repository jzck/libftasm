/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_inser_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 17:59:14 by ariard            #+#    #+#             */
/*   Updated: 2017/05/19 18:56:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			lst_insert_sort(t_list **head, 
				int (cmp)(void *elem1, void *elem2))
{
	t_list	**indirect;
	t_list	*ins;
	t_list	*tmp;

	indirect = head;
	while (indirect && *indirect && (*indirect)->next)
	{
		ins = *head;
		if ((cmp)(*indirect, (*indirect)->next) > 0)
			while (ins->next)
			{
				if ((cmp)(*indirect, ins->next) < 0)
				{
					tmp->next = (*indirect)->next;
					(*indirect)->next = ins->next;
					ins->next = (*indirect);
					indirect = &tmp;
					break;
				}
				ins = ins->next;
			}
		tmp = *indirect;
		indirect = &(*indirect)->next;
	}
}
