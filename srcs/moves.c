/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:30 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:17:30 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_game *g)
{
	t_stack	*a;
	char	*tmp;

	ft_putstr_fd("sa\n\0", 1);
	a = g->a;
	if (a->next)
	{
		tmp = ft_strdup(a->bin);
		free(a->bin);
		a->bin = a->next->bin;
		free(a->next->bin);
		a->next->bin = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	return (0);
}

int	ft_pa(t_game *game)
{
	t_stack	*new_a;

	ft_putstr_fd("pa\n\0", 1);
	if (game->b)
	{
		new_a = (t_stack *)malloc(sizeof(t_stack));
		if (!new_a)
			return (-1);
		new_a->bin = ft_strdup(game->b->bin);
		new_a->prev = NULL;
		new_a->next = game->a;
		game->a = new_a;
		new_a = game->b;
		game->b = game->b->next;
		free(new_a->bin);
		free(new_a);
		return (1);
	}
	return (0);
}

int	ft_pb(t_game *game)
{
	t_stack	*b;

	ft_putstr_fd("pb\n\0", 1);
	b = malloc(sizeof(t_stack));
	if (!b)
		return (-1);
	b->next = NULL;
	b->prev = NULL;
	if (game->a)
	{
		if (game->b)
			b->next = game->b;
		game->b = b;
		b->bin = ft_strdup(game->a->bin);
		b = game->a;
		game->a = game->a->next;
		free(b->bin);
		free(b);
		return (1);
	}
	return (0);
}

void	ft_ra(t_game *game)
{
	t_stack	*a;
	char	*first;

	a = game->a;
	first = ft_strdup(a->bin);
	while (a->next)
	{
		free(a->bin);
		a->bin = ft_strdup(a->next->bin);
		free(a->next->bin);
		a = a->next;
	}
	a->bin = ft_strdup(first);
	free(first);
	ft_putstr_fd("ra\n\0", 1);
}

void	ft_rra(t_game *game)
{
	t_stack	*a;
	char	*prec_bin;
	char	*current_bin;

	a = game->a;
	if (!(a->next))
		return ;
	prec_bin = ft_strdup(a->bin);
	free(a->bin);
	a = a->next;
	while (a)
	{
		current_bin = ft_strdup(a->bin);
		free(a->bin);
		a->bin = ft_strdup(prec_bin);
		free(prec_bin);
		prec_bin = ft_strdup(current_bin);
		free(current_bin);
		a = a->next;
	}
	game->a->bin = ft_strdup(prec_bin);
	free(prec_bin);
	free(current_bin);
	ft_putstr_fd("rra\n\0", 1);
}
