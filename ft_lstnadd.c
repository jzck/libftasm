#include "libft.h"

void	ft_lstnadd(t_list **alst, t_list *new, int n)
{
	t_list	*lst;
	int		i;

	lst = *alst;
	if (lst)
	{
		i = 0;
		while (lst->next && i < n)
		{
			lst = lst->next;
			i++;
		}
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}
