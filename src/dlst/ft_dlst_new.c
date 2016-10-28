#include "libft.h"

t_dlist	*ft_dlst_new(void const *content, size_t content_size)
{
	t_dlist	*new;

	if (!content)
	{
		new = malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = 0;
		new->content = NULL;
	}
	else
	{
		new = (t_dlist *)malloc(sizeof(*new));
		if (!new)
			return (NULL);
		new->content_size = content_size;
		new->content = ft_memalloc(content_size + 1);
		ft_memcpy(new->content, content, content_size);
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
