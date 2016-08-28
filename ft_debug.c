#include "libft.h"
#include <stdio.h>

void	ft_debug(void)
{
	static int n = 0;

	n++;
	ft_putendl("----------");
	printf(" check %02i\n", n);
	ft_putendl("----------");
}
