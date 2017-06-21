/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_generator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:21:30 by ariard            #+#    #+#             */
/*   Updated: 2017/06/21 19:54:30 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

struct s_list	*hashtab_generator(t_hashtab *htb, char init)
{
	static int		bucket;
	static t_list	*tmp;
	static t_list	*prev;

	if (init)
	{
		bucket = 0;
		tmp = htb->head[bucket];
		return (NULL);
	}
	while (!tmp && ++bucket < htb->capacity)
		tmp = htb->head[bucket];
	prev = tmp;
	if (tmp)
		tmp = tmp->next;
	return (prev);
}
