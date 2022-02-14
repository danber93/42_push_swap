#include "push_swap.h"

void	ft_last_two(t_game *g)
{
	t_stack	*b;
	int		i;

	i = 0;
	b = g->b;
	while (b && i < 8)
	{
		if (!(ft_is_bigger(b->bin, g->a->bin) && ft_is_bigger(b->bin, g->a->next->next->bin)))
		{
			ft_pa(g);
			ft_putstr_fd("pa\n\0", 1);
		}
		else if (ft_is_bigger(b->bin, g->a->bin) && ft_is_bigger(b->bin, g->a->next->next->bin))
		{
			ft_pa(g);
			ft_putstr_fd("pa\n\0", 1);
			ft_ra(g);
			ft_putstr_fd("ra\n\0", 1);
		}
		else
		{
			ft_ra(g);
			ft_putstr_fd("ra\n\0", 1);
		}
		b = g->b;
		i++;
		print_game(g);
	}
}

void	ft_stack_five(t_game *g)
{
	ft_pb(g);
	ft_putstr_fd("pb\n\0", 1);
	ft_pb(g);
	ft_putstr_fd("pb\n\0", 1);
	ft_stack_three(g);
	print_game(g);
	ft_last_two(g);
}

// TODO
//  finire di fixare la logica per il 5.. lo stack three lo ordina bene, ma poi rimangono i due da spostare da b ad a mentre si ruota lo stack a