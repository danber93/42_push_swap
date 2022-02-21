#include "push_swap.h"

int	ft_bt_inorder(t_node *node, int	*arr, int j)
{
	if (node->left)
		j = ft_bt_inorder(node->left, arr, j);
	arr[j] = node->value;
	j++;
	if (node->right)
		j = ft_bt_inorder(node->right, arr, j);
	return (j);
}

// child 0 = left child, child 1 = right child
void	ft_add_node(t_node *node, int n, int child)
{
	if (child == 0)
	{
		node->left = malloc(sizeof(t_node));
		node->left->value = n;
		node->left->left = NULL;
		node->left->right = NULL;
	}
	else
	{
		node->right = malloc(sizeof(t_node));
		node->right->value = n;
		node->right->left = NULL;
		node->right->right = NULL;
	}
}

void	ft_pop_btree(t_node *node, int n)
{
	if (n < node->value)
	{
		if (node->left)
			ft_pop_btree(node->left, n);
		else
			ft_add_node(node, n, 0);
	}
	else
	{
		if (node->right)
			ft_pop_btree(node->right, n);
		else
			ft_add_node(node, n, 1);
	}
}

t_node	*ft_init_btree(char **av)
{
	t_node	*root;
	int		tmp;
	int		i;

	root = malloc(sizeof(t_node));
	if (!root)
		return (NULL);
	tmp = ft_atoi(av[1]);
	root->value = tmp;
	root->left = NULL;
	root->right = NULL;
	i = 2;
	while (av[i])
	{
		tmp = ft_atoi(av[i]);
		ft_pop_btree(root, tmp);
		i++;
	}
	return (root);
}

int	*ft_pop_arr(t_node *root, int ac)
{
	int	*arr;

	arr = ft_calloc(sizeof(int), ac);
	ft_bt_inorder(root, arr, 0);
	return (arr);
}
