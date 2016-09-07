#include "libft.h"
#include <stdio.h>

void	ft_debug(void)
{
	static int n = 0;

	n++;
	printf("----------\n check %02i\n----------\n", n);
	fflush(stdout);
}
