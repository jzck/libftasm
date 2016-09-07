#include "libft.h"

t_list	*ft_lstnew_range(int a, int b)
{
	t_list	*lst;

	if (a >= b)
		return (NULL);
	lst = NULL;
	while (a < b)
	{
		b--;
		ft_lstadd(&lst, ft_lstnew(&b, sizeof(int)));
	}
	return (lst);
}
