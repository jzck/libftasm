/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:21:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:21:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

struct	s_dlist
{
	void			*content;
	size_t			content_size;
	struct s_dlist	*next;
	struct s_dlist	*prev;
};

typedef struct s_dlist	t_dlist;

void	ft_dlst_add_after(t_dlist **alst, t_dlist *new);
void	ft_dlst_add_before(t_dlist **alst, t_dlist *new);
void	ft_dlst_delone(t_dlist **alst, void (*del)(void *, size_t));
int		ft_dlst_size(t_dlist *list);
t_dlist	*ft_dlst_new(void const *content, size_t content_size);
t_dlist	*ft_dlst_last(t_dlist *list);
char	*ft_dlsttostr(t_dlist *list);

#endif
