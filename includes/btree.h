#ifndef BTREE_H
# define BTREE_H

#include "libft.h"

typedef struct s_btree		t_btree;

struct	s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
};

t_btree	*btree_create_node(void *item);

void	btree_insert_data(
		t_btree **root,
		void *item,
		int (*cmpf)(void *, void *));

void	*btree_search_item(t_btree *root,
		void *data_ref, int (*cmpf)(void *, void *));

int		btree_level_count(t_btree *root);
void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

#endif
