#include "libft.h"

int		ft_dlst_size(t_dlist *list)
{
	int		size;
	t_dlist	*tmp;

	size = 0;
	if (list)
		size++;
	tmp = list;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp->prev)
	{
		size++;
		tmp = tmp->prev;
	}
	return (size);
}
