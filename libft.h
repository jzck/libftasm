#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** PART_1
*/
void	ft_bzero(void *i, size_t t);
char	*ft_strcat(char *c, char *d);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
int		ft_isalnum(int i);
int		ft_isascii(int i);
int		ft_isprint(int i);
int		ft_toupper(int i);
int		ft_tolower(int i);
int		ft_puts(char *s);

/*
** PART_2
*/
int		ft_strlen(char *s);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
char	*ft_strdup(const char *s1);

/*
** PART_3
*/
void	ft_cat(int fd);

/*
** PART_BONUS
*/
int		ft_isupper(int i);
int		ft_islower(int i);
int		ft_putchar(int i);
int		ft_min(int a, int b);
int		ft_max(int a, int b);
