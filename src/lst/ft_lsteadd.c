#include "libft.h"

void	ft_lsteadd(t_list **alst, t_list *new)
{
	t_list	*lst;

	lst = *alst;
	new->next = NULL;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}
