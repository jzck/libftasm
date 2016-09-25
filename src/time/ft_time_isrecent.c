#include "libft.h"

int		ft_time_isrecent(time_t event)
{
	time_t	now;

	now = time(&now);
	if (now - event > 0 && now - event < 6*365/12*24*60*60)
		return (1);
	else
		return (0);
}
