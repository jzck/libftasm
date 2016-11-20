/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:06:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/16 11:24:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"
int _print_t(t_btree *tree, int is_left, int offset, int depth, char s[20][255], char *(*printer)(void *))
{
	char b[20];
	int width = 5;

	if (!tree)
		return 0;
	/* ft_printf("new tree elem: %s\n", printer(tree)); */
	sprintf(b, "%5s", printer(tree->item));
	int left  = _print_t(tree->left,  1, offset,                depth + 1, s, printer);
	int right = _print_t(tree->right, 0, offset + left + width, depth + 1, s, printer);
#ifdef COMPACT
	for (int i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (int i = 0; i < width + right; i++)
			s[depth - 1][offset + left + width/2 + i] = '-';
		s[depth - 1][offset + left + width/2] = '.';
	}
	else if (depth && !is_left)
	{
		for (int i = 0; i < left + width; i++)
			s[depth - 1][offset - width/2 + i] = '-';
		s[depth - 1][offset + left + width/2] = '.';
	}
#else
	for (int i = 0; i < width; i++)
		s[2 * depth][offset + left + i] = b[i];
	if (depth && is_left)
	{
		for (int i = 0; i < width + right; i++)
			s[2 * depth - 1][offset + left + width/2 + i] = '-';
		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset + left + width + right + width/2] = '+';
	}
	else if (depth && !is_left) {
		for (int i = 0; i < left + width; i++)
			s[2 * depth - 1][offset - width/2 + i] = '-';
		s[2 * depth - 1][offset + left + width/2] = '+';
		s[2 * depth - 1][offset - width/2 - 1] = '+';
	}
#endif
	return (left + width + right);
}

void	btree_print(t_btree *tree, char *(*printer)(void *))
{
	char s[20][255];
	char empty[255];
	/* for (int i = 0; i < 20; i++) */
	/* 	s[i][1] = 0; */
	for (int i = 0; i < 20; i++)
		sprintf(s[i], "%80s", " ");
	sprintf(empty, "%80s", " ");
	_print_t(tree, 0, 0, 0, s, printer);
	for (int i = 0; i < 20; i++)
	{
		if (ft_strcmp(s[i], empty) == 0)
			break ;
		printf("%s\n", s[i]);
	}
}
