#include "libft.h"

t_list	*ft_lst_filter(t_list *lst, void const *data_ref, t_list *(*f)(t_list *elem, void const *))
{
	t_list	*out;
	t_list	*elem;

	out = NULL;
	while (lst)
	{
		elem = (*f)(lst, data_ref);
		/* printf("size=%zu\n", elem->content_size); */
		/* printf("content=%i\n", *(int*)elem->content); */
		/* fflush(stdout); */
		elem = ft_lstnew(elem->content, elem->content_size);
		/* printf("size=%zu\n", elem->content_size); */
		/* printf("content=%i\n", *(int*)elem->content); */
		/* fflush(stdout); */
		ft_lsteadd(&out, elem);
		lst = lst->next;
	}
	/* ft_lst_print(out, &ft_putnbr); */
	return (out);
}
