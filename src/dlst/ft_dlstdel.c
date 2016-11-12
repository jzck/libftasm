#include "libft.h"

void	ft_dlstdel(t_dlist **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		ft_dlstdel(&(*alst)->next, del);
		ft_dlstdel(&(*alst)->prev, del);
	}
	ft_dlstdelone(alst, del);
}
