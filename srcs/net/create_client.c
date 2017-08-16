#include "libft.h"

int		create_client(char *addr, int port, char *protoname)
{
	int					sock;
	struct protoent		*proto;
	struct sockaddr_in	sin;

	if (!(proto = getprotobyname(protoname)))
		return (-1);
	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
	sin.sin_family = AF_INET;
	sin.sin_port = htons(port);
	sin.sin_addr.s_addr = inet_addr(addr);
	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) < 0)
		return (-1);
	return (sock);
}

void	listener(int domain, int sock, int proto, void (*handler)(void *buf, int bytes, struct sockaddr_in *addr))
{	int sd;
	struct sockaddr_in addr;
	unsigned char buf[1024];

	sd = socket(domain, sock, proto);
	if (sd < 0)
	{
		perror("listener socket");
		exit(0);
	}
	for (;;)
	{	int bytes;
		socklen_t len=sizeof(addr);

		bzero(buf, sizeof(buf));
		bytes = recvfrom(sd, buf, sizeof(buf), 0, (struct sockaddr*)&addr, &len);
		if (bytes > 0 && handler)
				handler(buf, bytes, &addr);
		else
			perror("recvfrom");
	}
	exit(0);
}
