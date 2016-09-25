#include "libft.h"

int		ft_xattr_count(char *path)
{
	ssize_t		listlen;
	char		list[FT_XATTR_SIZE];
	int			i;
	int			count;

	i = 0;
	listlen = listxattr(path, list, FT_XATTR_SIZE, XATTR_NOFOLLOW);
	if (listlen == -1)
		return (-1);
	count = 0;
	while (i < listlen)
	{
		i += ft_strlen(list) + 1;
		count++;
	}
	return (count);
}
