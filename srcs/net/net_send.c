#include "libft.h"

int		net_send(int sock, char *msg, int size)
{
	int		ack;

	if (write(sock, msg, size) < 0)
		return (-1);
	if (read(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	if (ntohs(ack) != ACK)
		return (1);
	return (0);
}
