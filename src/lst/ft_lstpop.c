#include "libft.h"

t_list	*ft_lstpop(t_list **lst)
{
	t_list	*top;

	top = *lst;
	if (*lst)
		*lst = (*lst)->next;
	return (top);
}
