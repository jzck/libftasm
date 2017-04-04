#include "libft.h"

int		net_get(int sock, char *msg, int size)
{
	int		ack;

	ack = htons(ACK);
	if (read(sock, msg, size) < 0)
		return (-1);
	if (write(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	return (0);
}
