#ifndef FTXATTR_H
# define FTXATTR_H
# define FT_XATTR_SIZE 10000
# include <sys/types.h>
# include <sys/xattr.h>

int		ft_xattr_print(char *path);
int		ft_xattr_count(char *path);
#endif
