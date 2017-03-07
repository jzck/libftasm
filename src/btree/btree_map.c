#include "btree.h"

t_btree		*btree_map(t_btree *root, void *(*f)(void *))
{
	t_btree		*new;

	if (!root)
		return (NULL);
	new = btree_create_node(root->item, root->content_size);
	new->item = (*f)(new->item);
	new->left = btree_map(root->left, f);
	new->right = btree_map(root->right, f);
	return (new);
}
