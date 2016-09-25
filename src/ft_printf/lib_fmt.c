#include "ftprintf.h"

t_fmt	*ft_fmt_init(void)
{
	t_fmt	*fmt;

	fmt = (t_fmt *)malloc(sizeof(t_fmt) + 1);
	ft_bzero(fmt->flags, 6);
	/* fmt->flags.hash = 0; */
	/* fmt->flags.zero = 0; */
	/* fmt->flags.minus = 0; */
	/* fmt->flags.space = 0; */
	/* fmt->flags.plus = 0; */
	ft_bzero(fmt->modifier, 3);
	fmt->conversion = '\0';
	fmt->width = 0;
	fmt->precision = 0;
	fmt->valid = 0;
	return (fmt);
}

void	ft_fmt_print(t_fmt *fmt)
{
	printf("\n---\n");
	printf("valid: %i\n", fmt->valid);
	printf("flags: %s\n", fmt->flags);
	printf("width: %i\n", fmt->width);
	printf("prec.: %i\n", fmt->precision);
	printf("modif: %s\n", fmt->modifier);
	printf("conv.: %c\n", fmt->conversion);
	printf("---\n");
	fflush(stdout);
}
