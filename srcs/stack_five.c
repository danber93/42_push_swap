/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_five.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:18:29 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:18:29 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_order_stack(t_game *g)
{
	int		pos;

	pos = ft_find_bin(g, "000");
	while (pos > 0)
	{
		ft_ra(g);
		pos--;
	}
}

void	ft_put_100(t_game *g)
{
	t_stack	*a;
	int		pos;

	a = g->a;
	pos = ft_find_bin(g, "011");
	if (pos == 0)
	{
		ft_ra(g);
		ft_pa(g);
	}
	if (pos == 1)
	{
		ft_ra(g);
		ft_ra(g);
		ft_pa(g);
	}
	if (pos == 2)
	{
		ft_rra(g);
		ft_pa(g);
	}
	if (pos == 3)
		ft_pa(g);
}

void	ft_ultimate_utils(t_game *g, int pos)
{
	if (pos == 2)
	{
		ft_ra(g);
		ft_ra(g);
		ft_pa(g);
	}
	if (pos == 3)
	{
		ft_rra(g);
		ft_pa(g);
	}
	ft_order_stack(g);
}

void	ft_ultimate(t_game *g)
{
	t_stack	*a;
	int		pos;

	a = g->a;
	pos = ft_position(a, g->b->bin);
	if (ft_equals(g->b->bin, "100"))
	{
		ft_put_100(g);
		ft_order_stack(g);
	}
	else
	{
		if (pos == 0)
			ft_pa(g);
		if (pos == 1)
		{
			ft_ra(g);
			ft_pa(g);
		}
		ft_ultimate_utils(g, pos);
	}
}

void	ft_stack_five(t_game *g)
{
	ft_pb(g);
	ft_pb(g);
	ft_stack_three(g);
	ft_penultimate(g);
	ft_ultimate(g);
}
