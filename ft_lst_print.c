#include "libft.h"

void	ft_lst_print(t_list *list, void (*printer)())
{
	while (list)
	{
		ft_putstr("[");
		(*printer)(list->content);
		ft_putstr("]->");
		list = list->next;
	}
	ft_putendl("X\n");
}
