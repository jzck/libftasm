#include "libft.h"

void	ft_lst_cfree(void *ptr, size_t size)
{
	(void)size;
	if (ptr)
		free(ptr);
}
