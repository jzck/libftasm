#include "libft.h"

void	ft_dlst_add_after(t_dlist **alst, t_dlist *new)
{
	if (new)
	{
		new->prev = (*alst);
		if (*alst)
			new->next = (*alst)->next;
		if (new->next)
			new->next->prev = new;
		if (new->prev)
			new->prev->next = new;
		*alst = new;
	}
}
