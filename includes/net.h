#ifndef NET_H
# define NET_H

# define ACK		2
# define NACK		3

# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>

int		create_server(int port, int backlog, char *protoname);
int		create_client(char *addr, int port, char *protoname);
void	listener(int domain, int sock, int proto, void (*handler)(void *buf, int bytes, struct sockaddr_in *addr));

int		net_send(int sock, char *msg, int size);
int		net_get(int sock, char *msg, int size);
int		net_get_fd(int sock, int fd, int size);

#endif
