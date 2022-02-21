#include "push_swap.h"

void	ft_rotate_a(t_game *g)
{
	ft_ra(g);
}

void	ft_move_to_b(t_game *g)
{
	ft_pb(g);
}

int	ft_first_hit(t_game *g)
{
	ft_ra(g);
	return (1);
}

/* Iterate on stack a */
void	ft_it_a(t_game *g, char *first, int bit)
{
	t_stack	*a;
	int		hit;

	a = g->a;
	hit = 0;
	while (a && hit != 2)
	{
		if (!(ft_strncmp(a->bin, first, ft_strlen(first))) && hit == 0)
			hit = ft_first_hit(g);
		else if (!(ft_strncmp(a->bin, first, ft_strlen(first))) && hit == 1)
			hit = 2;
		else if ((a->bin)[bit - 1] == '0')
			ft_move_to_b(g);
		else if ((a->bin)[bit - 1] == '1')
			ft_rotate_a(g);
		a = g->a;
	}
}

void	ft_radix_sort(t_game *g)
{
	int		bits;
	char	*first;

	bits = ft_strlen(g->a->bin);
	while (bits > -1)
	{
		first = ft_find_first(g->a, bits - 1);
		if (first != NULL)
		{
			ft_it_a(g, first, bits);
			ft_it_b(g);
		}
		bits--;
	}
	free(first);
}
