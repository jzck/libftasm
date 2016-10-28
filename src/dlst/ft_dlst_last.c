#include "libft.h"

t_dlist	*ft_dlst_last(t_dlist *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
