#include "push_swap.h"

int	ft_swap(t_stack *stack)
{
	int	tmp;

	if (stack->next)
	{
		tmp = stack->num;
		stack->num = stack->next->num;
		stack->next->num = tmp;
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
		new_a->num = game->b->num;
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
	t_stack	*new_b;

	if (game->a)
	{
		new_b = (t_stack *)malloc(sizeof(t_stack));
		new_b->num = game->a->num;
		new_b->prev = NULL;
		new_b->next = game->b;
		game->b = new_b;
		/* uso new_b per liberare il primo elemento della lista a */
		new_b = game->a;
		game->a = game->a->next;
		free(new_b);
		return (1);
	}
	return (0);
}

void	ft_ra(t_stack *a)
{
	int	first;

	first = a->num;
	while(a->next)
	{
		a->num = a->next->num;
		a = a->next;
	}
	a->num = first;
}

void	ft_rb(t_stack *b)
{
	int	first;

	first = b->num;
	while(b->next)
	{
		b->num = b->next->num;
		b = b->next;
	}
	b->num = first;
}

void	ft_rr(t_game *game)
{
	ft_ra(game->a);
	ft_rb(game->b);
}
