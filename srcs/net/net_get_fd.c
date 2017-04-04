#include "libft.h"

int		net_get_fd(int sock, int fd, int size)
{
	int		ack;
	char	msg[size];

	ack = htons(ACK);
	if (read(sock, msg, size) < 0)
		return (-1);
	if (write(sock, (char*)&ack, sizeof(ack)) < 0)
		return (-1);
	if (write(fd, msg, size) < 0)
		return (-1);
	return (0);
}
