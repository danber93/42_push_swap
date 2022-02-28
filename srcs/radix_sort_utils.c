/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:18:18 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:18:18 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_find_first(t_stack *a, int bit)
{
	char	*first;

	first = NULL;
	while (a)
	{
		if ((a->bin)[bit] == '1')
		{
			first = ft_strdup(a->bin);
			return (first);
		}
		a = a->next;
	}
	return (first);
}

void	ft_it_b(t_game *g)
{
	t_stack	*b;

	b = g->b;
	while (b)
	{
		ft_pa(g);
		b = g->b;
	}
}
