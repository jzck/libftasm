#include "libft.h"

void	ft_dlst_add_before(t_dlist **alst, t_dlist *new)
{
	if (new)
	{
		new->next = (*alst);
		if (*alst)
			new->prev = (*alst)->prev;
		if (new->next)
			new->next->prev = new;
		if (new->prev)
			new->prev->next = new;
		*alst = new;
	}
}
