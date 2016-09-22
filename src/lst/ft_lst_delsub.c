#include "libft.h"

void	ft_lst_delsub(t_list **alst, t_list *sub, int (*cmp)(), void (*del)(void *, size_t))
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = NULL;
	current = *alst;
	tmp = NULL;
	while (current && sub)
	{
		if ((*cmp)(current->content, sub->content) == 0)
		{
			if (current == *alst)
				*alst = current->next;
			else
				last->next = current->next;
			tmp = current;
			current = current->next;
			sub = sub->next;
			ft_lstdelone(&tmp, del);
		}
		else
		{
			last = current;
			current = current->next;
		}
		if (!current && sub)
			current = *alst;
	}
}
