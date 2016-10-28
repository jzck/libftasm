#include "libft.h"

void	ft_dlst_delone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	tmp = *alst;
	if (tmp)
	{
		if (del)
			(*del)(tmp->content, tmp->content_size);
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->prev)
			*alst = tmp->prev;
		else
			*alst = tmp->next;
		free(tmp);
	}
}
