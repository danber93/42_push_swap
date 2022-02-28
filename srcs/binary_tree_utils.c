/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:56 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:17:56 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_btree(t_node *node)
{
	if (node->left)
		ft_free_btree(node->left);
	if (node->right)
		ft_free_btree(node->right);
	free(node);
}
