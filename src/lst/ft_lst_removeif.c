#include "libft.h"

t_list	*ft_lst_removeif(t_list **alst, void *data_ref, int (*cmp)())
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = NULL;
	tmp = NULL;
	current = *alst;
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
			return (tmp);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
	return (NULL);
}

