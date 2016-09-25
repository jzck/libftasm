#include "libft.h"

char	*ft_path_notdir(char *path)
{
	char	*slash;
	char	*ret;

	ret = path;
	if ((slash = ft_strrchr(path, '/')))
		ret = slash + 1;
	return (ret);
}
