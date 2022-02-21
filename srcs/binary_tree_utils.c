#include "push_swap.h"

void	ft_free_btree(t_node *node)
{
	if (node->left)
		ft_free_btree(node->left);
	if (node->right)
		ft_free_btree(node->right);
	free(node);
}
