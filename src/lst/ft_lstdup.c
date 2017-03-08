/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 00:14:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/08 01:44:22 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstdup(t_list **lst, void *(*f)(void *content))
{
	t_list	*new;
	t_list	*tp;
	void	*temp;
		

	new = NULL;
	tp = *lst;
	while (tp)
	{
		temp = (*f)((*lst)->content);
		ft_lstadd(&new, ft_lstnew(temp, sizeof(temp)));
		tp = tp->next;
	}
	ft_lst_reverse(&new);
	return (new);	
}
