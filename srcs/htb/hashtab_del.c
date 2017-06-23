/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtab_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 17:04:24 by ariard            #+#    #+#             */
/*   Updated: 2017/06/22 22:45:04 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtab.h"

void		hashtab_del(t_hashtab *htb, void *key,
			int (*match)(const void *, const void *),
			void (*del)(void *, size_t))
{
	int		bucket;

	if ((bucket = htb->hashfunc(key, htb->capacity)))
		ft_lst_delif(&htb->head[bucket], key, match, del);
}
