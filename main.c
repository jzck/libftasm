#include "libft.h"
#include <ctype.h>
#include <math.h>

int ft_putstr(const char *str)
{
	return (write(1, str, strlen(str)));
}

int ft_putnstr(const char *str, size_t n)
{
	return (write(1, str, n));
}

int test_bzero()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	int len = strlen(str);
	int result = 0;
	int i;

	ft_bzero(NULL, 250);

	bzero(str_cmp, 1);
	ft_bzero(str, 1);
	i = -1;
	++result;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			printf("Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	bzero(str_cmp + 5, 4);
	ft_bzero(str + 5, 4);
	++result;
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			printf("Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	bzero(str_cmp + 2, len - 3);
	ft_bzero(str + 2, len - 3);
	++result;
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			printf("Failed[%d]: %c vs %c at pos: %d\n", result, str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	return (0);
}

int test_strcat()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char str[20] = "first_";
	char str2[] = "second\n";
	char str_cmp[20] = "first_";
	char str_cmp2[] = "second\n";
	int len = 20;
	int i;

	strcat(str_cmp, str_cmp2);
	ft_strcat(str, str2);
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			printf("Failed: %c vs %c at pos: %d\n", str[i], str_cmp[i], i);
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			return(1);
		}
	}
	return (0);
}

int test_isalpha()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isalpha(a) == 0) != (ret_cmp = isalpha(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return (1);
		}
	}
	return (0);
}

int test_isdigit()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isdigit(a) == 0) != (ret_cmp = isdigit(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_isascii()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isascii(a) == 0) != (ret_cmp = isascii(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_isalnum()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isalnum(a) == 0) != (ret_cmp = isalnum(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_isprint()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isprint(a) == 0) != (ret_cmp = isprint(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_toupper()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	while (++a < 127)
	{
		if (ft_toupper(a) != toupper(a))
		{
			printf("FAILED: %c [%d]\n", a, a);
			return(1);
		}
	}
	return (0);
}

int test_tolower()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	while (++a < 127)
	{
		if (ft_tolower(a) != tolower(a))
		{
			printf("FAILED: %c [%d]\n", a, a);
			return(1);
		}
	}
	return (0);
}

int test_puts()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char str[] = "It's a char line you have to print. Not this one";
	str[35] = 0;
	int ret, ret_cmp;
	printf("Original:|"); ret = puts("");printf("|\n");
	printf("Notre   :|"); ret_cmp = ft_puts("");printf("|\n");
#ifdef __APPLE__
	if (ret != ret_cmp)
	{
		printf("FAILED: %d should be %d\n", ret_cmp, ret);
		return (1);
	}
#endif
#ifdef __APPLE__
// puts(NULL) segfaults on linux because the compiler lets you shoot yourself
	printf("Original:|"); ret = puts(NULL);printf("|\n");
	printf("Notre   :|"); ret_cmp = ft_puts(NULL);printf("|\n");
	if (ret != ret_cmp)
	{
		printf("FAILED: %d should be %d\n", ret_cmp, ret);
		return (1);
	}
#endif
	printf("Notre   :|"); ret = ft_puts(str);printf("|\n");
	printf("Original:|"); ret_cmp = puts(str);printf("|\n");
#ifdef __APPLE__
	if (ret != ret_cmp)
	{
		printf("FAILED: %d should be %d\n", ret_cmp, ret);
		return (1);
	}
#endif
	return (0);
}

int test_strlen()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char str[] = "zagaga";
	int ret, ret_cmp;
	ret = ft_strlen(str);
	ret_cmp = strlen(str);
	if (ret != ret_cmp)
	{
		printf("FAILED: %d vs %d (on %s)", ret, ret_cmp, str);
		return (1);
	}
	ret = ft_strlen(NULL);
	ret_cmp = 0;
	if (ret != ret_cmp)
	{
		printf("FAILED: %d vs %d (on nullptr)", ret, ret_cmp);
		return (1);
	}
	return (0);
}

int test_memset()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	char *ret, *ret_cmp;
	int len = strlen(str);
	int result = 0;
	int i;

	while (++a < 127)
	{
		++result;
		if (ft_memset(NULL, a, 250) != NULL)
		{
			printf("Failed[%d]: memset on NULL\n", result);
			return (1);
		}
		ret_cmp = memset(str_cmp, a, 1);
		ret = ft_memset(str, a, 1);
		i = -1;
		++result;
		while (++i < len)
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				printf("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 5, a, 4);
		ret = ft_memset(str + 5, a, 4);
		++result;
		i = -1;
		while (++i < (len - 5))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				printf("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
		ret_cmp = memset(str_cmp + 2, a, len - 3);
		ret = ft_memset(str + 2, a, len - 3);
		++result;
		i = -1;
		while (++i < (len - 2))
		{
			if (ret[i] != ret_cmp[i])
			{
				ft_putnstr(ret, len);
				ft_putnstr(ret_cmp, len);
				printf("Failed[%d]: %c vs %c at pos: %d/%d\n", result, ret[i], ret_cmp[i], i, len);
				return(1);
			}
		}
	}
	return (0);
}

int test_memcpy()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char str[] = "Bonjour je suis une chaine de char!\n";
	char str_cmp[] = "Bonjour je suis une chaine de char!\n";
	char ret[100], ret_cmp[100];
	char *me, *cmp;
	int len = strlen(str);
	int result = 0;
	int i;

	++result;
	if (ft_memcpy(NULL, str, 250) != NULL)
	{
		printf("Failed[%d]: memcpy on dst=NULL\n", result);
		return (1);
	}
	++result;
	if (ft_memcpy(ret, NULL, 250) != ret)
	{
		printf("Failed[%d]: memcpy on src=NULL\n", result);
		return (1);
	}
	cmp = memcpy(ret_cmp, str_cmp, len);
	me = ft_memcpy(ret, str, len);
	i = -1;
	++result;
	while (++i < len)
	{
		if (me[i] != cmp[i])
		{
			ft_putnstr(ret, len);
			ft_putnstr(ret_cmp, len);
			printf("Failed[%d]: %c vs %c at pos: %d/%d\n", result, me[i], cmp[i], i, len);
			return(1);
		}
	}
	memcpy(ret_cmp + len, str_cmp, len);
	ft_memcpy(ret + len, str, len);
	i = -1;
	++result;
	while (++i < 2 * len)
	{
		if (me[i] != cmp[i])
		{
			ft_putnstr(ret, 2 * len);
			ft_putnstr(ret_cmp, 2 * len);
			printf("Failed[%d]: %c vs %c at pos: %d/%d\n", result, me[i], cmp[i], i, 2 * len);
			return(1);
		}
	}
	return (0);
}

int test_strdup()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char *str;
	char *str_cmp;
	int len, len_cmp;
	int i;
	if ((str = ft_strdup(NULL)) != NULL)
	{
		printf("FAILED: not support NULL\n");
		return (1);
	}
	str = ft_strdup("Coucou");
	str_cmp = strdup("Coucou");
	len = strlen(str);
	len_cmp = strlen(str_cmp);
	if (len != len_cmp)
	{
		printf("FAILED: len is %d vs %d\n", len, len_cmp);
		return (1);
	}
	i = -1;
	while (++i < len)
	{
		if (str[i] != str_cmp[i])
		{
			ft_putnstr(str, len);
			ft_putnstr(str_cmp, len);
			printf("FAILED: %c vs %c\n", str[i], str_cmp[i]);
			return (1);
		}
	}
	free(str);
	free(str_cmp);

	return (0);
}

int test_cat(char **av)
{
	ft_putstr(__func__); ft_putstr(":\n");

	(void)av;
	ft_cat(0);
	ft_cat(open(__FILE__, O_RDONLY));
	ft_cat(open(av[0], O_RDONLY));
	ft_cat(-42);
	return (0);
}

int test_isupper()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_isupper(a) == 0) != (ret_cmp = isupper(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_islower()
{
	ft_putstr(__func__); ft_putstr(":\n");
	char a = -1;
	int ret, ret_cmp;
	while (++a < 127)
	{
		if ((ret = ft_islower(a) == 0) != (ret_cmp = islower(a) == 0))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	return (0);
}

int test_putchar()
{
	ft_putstr(__func__); ft_putstr(":\n");
	int a = -500;
	int ret, ret_cmp;
	while (++a < 500)
	{
		if ((ret = ft_putchar(a)) != (ret_cmp = putchar(a)))
		{
			printf("FAILED: %c [%d] => %d vs %d\n", a, a, ret, ret_cmp);
			return(1);
		}
	}
	ft_putstr(":\n");
	return (0);
}

int test_max()
{
	ft_putstr(__func__); ft_putstr(":\n");
	unsigned int a, b, ret, ret_cmp;
	int ans = 0;
	a = 5;
	b = 6;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = 6;
	b = 5;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -10;
	b = -12;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = -10;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -10;
	b = 12;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = 10;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = 0;
	b = 10;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = 0;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -2147483648;
	b = 2147483647;
	if ((ret = ft_max(a,b)) != (ret_cmp = fmax(a,b)))
	{
			dprintf(2, "FAILED max(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}

	return (ans);
}

int test_min()
{
	ft_putstr(__func__); ft_putstr(":\n");
	unsigned int a, b, ret, ret_cmp;
	int ans = 0;
	a = 5;
	b = 6;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = 6;
	b = 5;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -10;
	b = -12;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = -10;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -10;
	b = 12;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = 10;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = 0;
	b = 10;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -12;
	b = 0;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}
	a = -2147483648;
	b = 2147483647;
	if ((ret = ft_min(a,b)) != (ret_cmp = fmin(a,b)))
	{
			dprintf(2, "FAILED min(%d, %d) => %d vs %d\n",a,b,ret,ret_cmp);
			++ans;
		}

	return (ans);
}


int main(int argc, char **argv)
{
	(void)argc;
	setbuf(stdout, NULL);
	ft_putstr("\nPART 1:\n_______\n");
	if (
			test_bzero() ||
			test_strcat() ||
			test_isalpha() ||
			test_isdigit() ||
			test_isalnum() ||
			test_isascii() ||
			test_isprint() ||
			test_toupper() ||
			test_tolower() ||
			test_puts()
	   )
		return (1);
	ft_putstr("PART 2:\n_______\n");
	if (
			test_strlen() ||
			test_memset() ||
			test_memcpy() ||
			test_strdup()
	   )
		return (1);
	ft_putstr("\nPART 3:\n_______\n");
	if (test_cat(argv))
		return (1);
	ft_putstr("\nPART BONUS:\n_______\n");
	if (
			test_isupper() ||
			test_islower() ||
			test_putchar() ||
			test_min() ||
			test_max()
	   )
		return (1);
	puts("\033c\n\033[38;5;117mALL PASSED\n___________\n\033[0m");
	return (0);
}
