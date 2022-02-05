#include "push_swap.h"

int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->next)
	{
		tmp = stack->value;
		stack->value = stack->next->value;
		stack->next->value = tmp;
		return (1);
	}
	return (0);
}

int	ft_ss(t_game *game)
{
	ft_swap(game->a);
	ft_swap(game->b);
	return (1);
}

int ft_pa(t_game *game)
{
	t_stack	*new_a;

	if (game->b)
	{
		new_a = (t_stack *)malloc(sizeof(t_stack));
		new_a->value = game->b->value;
		new_a->prev = NULL;
		new_a->next = game->a;
		game->a = new_a;
		/* uso new_a per liberare il primo elemento della lista b */
		new_a = game->b;
		game->b = game->b->next;
		free(new_a);
		return (1);
	}
	return (0);
}

int ft_pb(t_game *game)
{
	t_stack	*b;

	b = malloc(sizeof(t_stack));
	if (!b)
		return (-1);
	b->next = NULL;
	b->prev = NULL;
	if (!b && game->a)
		game->b = b;
	if (game->a)
	{
		b->next = game->b;
		game->b = b;
		b->value = game->a->value;
		/* uso b per liberare il primo elemento della lista a */
		b = game->a;
		game->a = game->a->next;
		free(b);
		return (1);
	}
	return (0);
}

void	ft_ra(t_stack *a)
{
	int	first;

	first = a->value;
	while(a->next)
	{
		a->value = a->next->value;
		a = a->next;
	}
	a->value = first;
}

void	ft_rb(t_stack *b)
{
	int	first;

	first = b->value;
	while(b->next)
	{
		b->value = b->next->value;
		b = b->next;
	}
	b->value = first;
}

void	ft_rr(t_game *game)
{
	ft_ra(game->a);
	ft_rb(game->b);
}

void	ft_rra(t_game *game)
{
	t_stack	*a;
	int	prec_value;
	int	current_value;

	a = game->a;
	if (!(a->next))
		return;
	prec_value = a->value;
	a = a->next;
	while (a)
	{
		current_value = a->value;
		a->value = prec_value;
		prec_value = current_value;
		a = a->next;
	}
	game->a->value = prec_value;
}

void	ft_rrb(t_game *game)
{
	t_stack	*b;
	int	prec_value;
	int	current_value;

	b = game->b;
	if (!(b->next))
		return;
	prec_value = b->value;
	b = b->next;
	while (b)
	{
		current_value = b->value;
		b->value = prec_value;
		prec_value = current_value;
		b = b->next;
	}
	game->b->value = prec_value;
}

void	ft_rrr(t_game *game)
{
	ft_rra(game);
	ft_rrb(game);
}