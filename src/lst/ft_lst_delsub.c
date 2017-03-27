/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_delsub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:15 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/26 16:55:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_delsub(
		t_list **alst,
		t_list *sub,
		int (*cmp)(),
		void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if ((*cmp)((*indirect)->content, sub->content) == 0)
		{
			tmp = *indirect;
			(*indirect) = (*indirect)->next;
			sub = sub->next;
			ft_lstdelone(&tmp, del);
		}
		indirect = &(*indirect)->next;
	}
}
