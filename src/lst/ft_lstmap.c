#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;
	t_list	*elem;

	out = NULL;
	while (lst)
	{
		elem = (*f)(lst);
		if (elem)
			elem = ft_lstnew(elem->content, elem->content_size);
		ft_lsteadd(&out, elem);
		lst = lst->next;
	}
	return (out);
}
