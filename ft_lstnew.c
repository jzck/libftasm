#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	size_t	i;

	if (!content)
	{
		link = malloc(1);
		if (!link)
			return (NULL);
		link->next = NULL;
		link->content_size = 0;
		link->content = NULL;
	}
	else
	{
		link = ft_memalloc(sizeof(t_list) + content_size);
		if (!link)
			return (NULL);
		link->content_size = content_size;
		link->next = NULL;
		i = -1;
		while (++i < content_size)
			((char *)link->content)[i] = ((char *)content)[i];
	}
	return (link);
}
