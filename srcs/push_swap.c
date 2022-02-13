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

void ft_it_b(t_game *g)
{
	t_stack *b;

	b = g->b;
	while (b)
	{
		ft_pa(g);
		b = g->b;
	}
}

/* Iterate on stack a */
void	ft_it_a(t_game *g, char *first, int bit)
{
	t_stack	*a;
	int		visited;

	a = g->a;
	visited = 0;
	while (a && visited != 2)
	{
		if (!(ft_strncmp(a->bin, first, ft_strlen(first))) && visited == 0)
		{
			visited = 1;
			ft_ra(g);
			// printf("ra\n");
		}
		else if (!(ft_strncmp(a->bin, first, ft_strlen(first))) && visited == 1)
			visited = 2;
		else if ((a->bin)[bit - 1] == '0')
		{
			ft_pb(g);
			// printf("pb\n");
		}
		else if ((a->bin)[bit - 1] == '1')
		{
			ft_ra(g);
			// printf("ra\n");
		}
		a = g->a;
	}
}

void	ft_order(t_game	*g)
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
}