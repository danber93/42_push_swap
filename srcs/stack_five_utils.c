/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_five_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:18:26 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:18:26 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_equals(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (i < 3 && s1[i] == s2[i])
	{
		i++;
	}
	if (i == 3)
		return (1);
	return (0);
}

int	ft_biggest(t_game *g)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*last_a;

	a = g->a;
	b = g->b;
	last_a = g->a;
	while (last_a->next)
		last_a = last_a->next;
	if (ft_is_bigger(b->bin, a->bin) && ft_is_bigger(b->bin, last_a->bin))
		return (1);
	return (0);
}

int	ft_smallest(t_game *g)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*last_a;

	a = g->a;
	b = g->b;
	last_a = g->a;
	while (last_a->next)
		last_a = last_a->next;
	if (!(ft_is_bigger(b->bin, a->bin)) && !(ft_is_bigger(b->bin, last_a->bin)))
		return (1);
	return (0);
}

void	ft_penultimate_between_two(t_game *g)
{
	if (ft_is_bigger(g->b->bin, g->a->bin)
		&& !(ft_is_bigger(g->b->bin, g->a->next->bin)))
	{
		ft_ra(g);
		ft_pa(g);
		return ;
	}
	ft_rra(g);
	ft_pa(g);
}

void	ft_penultimate(t_game *g)
{
	t_stack	*a;

	a = g->a;
	if (ft_smallest(g))
	{
		ft_pa(g);
		return ;
	}
	else if (ft_biggest(g))
	{
		ft_pa(g);
		ft_ra(g);
		return ;
	}
	ft_penultimate_between_two(g);
}
