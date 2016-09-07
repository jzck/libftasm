#include "libft.h"

void	ft_lst_remove_if(
		t_list **begin_list,
		void *data_ref,
		int (*cmp)())
{
	t_list	*last;
	t_list	*current;
	t_list	*tmp;

	last = NULL;
	current = *begin_list;
	tmp = NULL;
	fflush(stdout);
	while (current)
	{
		if ((*cmp)(current->content, &data_ref) == 0)
		{
			if (current == *begin_list)
				*begin_list = current->next;
			else
				last->next = current->next;
			tmp = current;
			current = current->next;
			free(tmp);
		}
		else
		{
			last = current;
			current = current->next;
		}
	}
}

