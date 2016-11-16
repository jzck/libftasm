/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:06:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 18:26:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static void	print_offset(int offset)
{
	int i;
	for (i = 0; i < offset; ++i)
	{
		ft_putstr(" ");
	}
}

void		btree_print(t_btree* tree, void (*printer)(t_btree *tree))
{
	static int offset = 0;

	print_offset(offset);

	if (tree == NULL)
	{
		ft_putendl("-");
		return;
	}
	(*printer)(tree);

	offset += 3;
	btree_print(tree->right, printer);
	btree_print(tree->left, printer);
	offset -= 3;
}
