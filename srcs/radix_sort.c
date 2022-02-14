#include "push_swap.h"

/* Find the first "bin" with i-th bit == 1 */
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
		ft_putstr_fd("pa\n\0", 1);
		b = g->b;
	}
}

void	ft_rotate_a(t_game *g)
{
	ft_ra(g);
	ft_putstr_fd("ra\n\0", 1);
}

void	ft_move_to_b(t_game *g)
{
	ft_pb(g);
	ft_putstr_fd("pb\n\0", 1);
}

int	ft_first_hit(t_game *g)
{
	ft_ra(g);
	ft_putstr_fd("ra\n\0", 1);
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
