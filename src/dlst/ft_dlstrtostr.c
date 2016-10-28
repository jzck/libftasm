#include "libft.h"

char	*ft_dlsttostr(t_dlist *list)
{
	char	*str;

	if (!list)
		return (NULL);
	while (list->prev)
		list = list->prev;
	str = (char *)ft_strnew(sizeof(char) * (ft_dlst_size(list) + 2));
	/* list = ft_dlst_last(list); */
	while (list)
	{
		ft_strcat(str, (char *)list->content);
		list = list->next;
	}
	/* str = ft_strrev(str); */
	return (str);
}
