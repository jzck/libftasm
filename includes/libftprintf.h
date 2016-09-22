#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft.h"
# include <stdarg.h>
# define ALL_FLAGS "#0- +"
# define ALL_CONVERSIONS "sSpdDioOuUxXcC"

typedef struct	s_fmt
{
	char	flags[6];
	int		width;
	int		precision;
	char	modifier[3];
	char	conversion;
	int		valid;
}				t_fmt;

typedef	char	*(*t_converter)(t_fmt *fmt, va_list ap);

typedef struct	s_conv
{
	char		id;
	char		base[20];
	t_converter	converter;
	char		allowed_flags[6];
}				t_conv;

extern t_conv	g_convs[];

t_fmt	*ft_fmt_init(void);
void	ft_fmt_print(t_fmt *fmt);

int		ft_printf(const char *format, ...);
t_fmt	*ft_parse(char **format);
char	*ft_transform(t_fmt *fmt, va_list ap);

void	ft_fmt_error_conv(char conv);
void	ft_fmt_error_mod_conv(char *mod, char conv);
void	ft_fmt_error_flag_conv(char flag, char conv);
void	ft_fmt_error_flag_flag(char flag1, char flag2);

void	ft_fmt_simplify(t_fmt *fmt);
int		ft_fmt_validate_conversion(t_fmt *fmt);
void	ft_fmt_validate_flags(t_fmt *fmt);
void	ft_fmt_validate_mod(t_fmt *fmt);

char	*ft_signed_conversion(t_fmt *fmt, va_list ap);
char	*ft_unsigned_conversion(t_fmt *fmt, va_list ap);
char	*ft_str_conversion(t_fmt *fmt, va_list ap);
char	*ft_char_conversion(t_fmt *fmt, va_list ap);

void	ft_pad_left(char *str, t_fmt *fmt);
void	ft_pad_right(char *str, t_fmt *fmt);
void	ft_pad_sharp_o(char *str);
void	ft_pad_sharp_x(char *str, t_fmt *fmt);
void	ft_pad_sharp(char *str, t_fmt *fmt);
#endif
