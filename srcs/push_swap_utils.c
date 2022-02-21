#include "push_swap.h"

int	ft_n_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	ft_is_bigger(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (s1[i] == '1' && s2[i] == '0')
			return (1);
		if (s1[i] == '0' && s2[i] == '1')
			return (0);
		i++;
	}
	return (0);
}

int	ft_is_sorted(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a->next)
	{
		if (!(ft_is_bigger(a->bin, a->next->bin)))
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_is_solved(t_game *g)
{
	if (g->a)
		if (ft_is_sorted(g->a) && !(g->b))
			return (1);
	return (0);
}

void	ft_free_game(t_game *g)
{
	t_stack	*a;
	t_stack	*b;

	a = g->a;
	while (a)
	{
		free(a->bin);
		g->a = a->next;
		free(a);
		a = g->a;
	}
	b = g->b;
	while (b)
	{
		free(b->bin);
		g->b = b->next;
		free(b);
		b = g->b;
	}
	free(a);
	free(b);
	free(g);
}
