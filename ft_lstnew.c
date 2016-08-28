#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	size_t	i;

	link->next = NULL;
	if (!content)
	{
		link->content_size = 0;
		link->content = NULL;
	}
	else
	{
		link->content_size = content_size;
		link->content = ft_memalloc(content_size);
		if (!link->content)
			return (NULL);
		i = -1;
		while (++i < content_size)
			((char *)link->content)[i] = ((char *)content)[i];
	}
	return (link)
}
