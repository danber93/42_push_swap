#include "push_swap.h"

int		ft_biggest(t_game *g)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *last_a;

	a = g->a;
	b = g->b;
	last_a = g->a;
	while (last_a->next)
		last_a = last_a->next;
	if (ft_is_bigger(b->bin, a->bin) && ft_is_bigger(b->bin, last_a->bin))
		return (1);
	return (0);
}

int		ft_smallest(t_game *g)
{
	t_stack	*a;
	t_stack	*b;
	t_stack *last_a;

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
	if (ft_is_bigger(g->b->bin, g->a->bin) && !(ft_is_bigger(g->b->bin, g->a->next->bin)))
	{
		ft_ra(g);
		ft_putstr_fd("ra\n\0", 1);
		ft_pa(g);
		ft_putstr_fd("pa\n\0", 1);
		return;
	}
	ft_rra(g);
	ft_putstr_fd("rra\n\0", 1);
	ft_pa(g);
	ft_putstr_fd("pa\n\0", 1);
	return;
}

void	ft_penultimate(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_smallest(g))
	{
		ft_pa(g);
		ft_putstr_fd("pa\n\0", 1);
		return;
	}
	else if (ft_biggest(g))
	{
		ft_pa(g);
		ft_putstr_fd("pa\n\0", 1);
		ft_ra(g);
		ft_putstr_fd("ra\n\0", 1);
		return;
	}
	ft_penultimate_between_two(g);
}

void	ft_stack_five(t_game *g)
{
	ft_pb(g);
	ft_putstr_fd("pb\n\0", 1);
	ft_pb(g);
	ft_putstr_fd("pb\n\0", 1);
	print_game(g);
	ft_stack_three(g);
	printf("fine stack_three\n");
	print_game(g);
	ft_penultimate(g);
	print_game(g);
}

// TODO
//  finire di fixare la logica per il 5.. lo stack three lo ordina bene, ma poi rimangono i due da spostare da b ad a mentre si ruota lo stack a