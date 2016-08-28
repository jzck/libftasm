#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

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
		link = (t_list *)malloc(sizeof(link));
		if (!link)
			return (NULL);
		link->content_size = content_size;
		link->next = NULL;
		link->content = ft_memalloc(content_size);
		ft_memcpy(link->content, content, content_size);
	}
	return (link);
}
