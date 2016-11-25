/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 18:06:24 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/25 20:44:56 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

static int	print_t2(int data[5], char s[20][255], char b[20])
{
	int		width;
	int		i;

	width = 5;
	i = -1;
	while (++i < width)
		s[2 * data[depth]][data[offset] + data[left] + i] = b[i];
	i = -1;
	if (data[depth] && data[is_left])
	{
		while (++i < width + data[right])
			s[2 * data[depth] - 1]
				[data[offset] + data[left] + width / 2 + i] = '-';
		s[2 * data[depth] - 1][data[offset] + data[left] + width / 2] = '+';
		s[2 * data[depth] - 1]
			[data[offset] + data[left] + data[right] + 3 * width / 2] = '+';
	}
	else if (data[depth] && !data[is_left])
	{
		while (++i < width + data[left])
			s[2 * data[depth] - 1][data[offset] - width / 2 + i] = '-';
		s[2 * data[depth] - 1][data[offset] + data[left] + width / 2] = '+';
		s[2 * data[depth] - 1][data[offset] - width / 2 - 1] = '+';
	}
	return (data[left] + data[width] + right);
}

static int	print_t(t_btree *tree,
		int data[5], char s[20][255], char *(*printer)(void *))
{
	char	b[20];
	int		width;

	width = 5;
	if (!tree)
		return (0);
	sprintf(b, "%5s", printer(tree->item));
	data[left] = print_t(tree->left, (int[3]){
			1, data[offset], data[depth] + 1}, s, printer);
	data[right] = print_t(tree->right, (int[3]){
			0, data[offset] + data[left] + width, data[depth] + 1}, s, printer);
	return (print_t2(data, s, b));
}

void		btree_print(t_btree *tree, char *(*printer)(void *))
{
	char	s[20][255];
	char	empty[255];
	int		i;

	i = -1;
	while (++i < 20)
		sprintf(s[i], "%80s", " ");
	sprintf(empty, "%80s", " ");
	print_t(tree, (int[5]){0, 0, 0, 0, 0}, s, printer);
	i = -1;
	while (++i < 20)
	{
		if (ft_strcmp(s[i], empty) == 0)
			break ;
		printf("%s\n", s[i]);
	}
}
