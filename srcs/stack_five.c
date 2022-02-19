#include "push_swap.h"

int		ft_equals(char *s1, char *s2)
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
		ft_pa(g);
		return;
	}
	ft_rra(g);
	ft_pa(g);
	return;
}

void	ft_penultimate(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_smallest(g))
	{
		ft_pa(g);
		return;
	}
	else if (ft_biggest(g))
	{
		ft_pa(g);
		ft_ra(g);
		return;
	}
	ft_penultimate_between_two(g);
}

int		ft_is_not_consecutive(char *sa, char *sb)
{
	int		is_not_cons;
	char	*next;

	next = ft_strdup(sb);
	if (!next)
		return (-1);
	if (next[2] == '0')
		next[2] = '1';
	else if (next[1] == '1')
	{
		next[2] = '0';
		next[1] = '0';
		next[0] = '1';
	}
	else
	{
		next[1] = '1';
		next[2] = '0';
	}
	is_not_cons = ft_equals(sa, next);
	free(next);
	return (is_not_cons);
}

int		ft_position(t_stack *a, char *bin)
{
	t_stack	*s;
	int		i;

	s = a;
	i = 0;
	while (s && !(ft_is_not_consecutive(s->bin, bin)))
	{
		s = s->next;
		i++;
	}
	return (i);
}

int		ft_find_bin(t_game *g, char *bin)
{
	t_stack *a;
	int		pos;

	a = g->a;
	pos = 0;
	while (ft_strncmp(a->bin, bin, 3))
	{
		pos++;
		a = a->next;
	}
	return (pos);
}

void	ft_order_stack(t_game *g)
{
	int		pos;

	pos = ft_find_bin(g, "000");
	while (pos > 0)
	{
		ft_ra(g);
		pos--;
	}
}

void	ft_put_100(t_game *g)
{
	t_stack	*a;
	int		pos;

	a = g->a;
	pos = ft_find_bin(g, "011");
	if (pos == 0)
	{
		ft_ra(g);
		ft_pa(g);
	}
	if (pos == 1)
	{
		ft_ra(g);
		ft_ra(g);
		ft_pa(g);
	}
	if (pos == 2)
	{
		ft_rra(g);
		ft_pa(g);
	}
	if (pos == 4)
		ft_pa(g);
}

void	ft_ultimate(t_game *g)
{
	t_stack	*a;
	int		pos;

	a = g->a;
	if (ft_equals(g->b->bin, "100"))
		ft_put_100(g);
	else
	{
		pos = ft_position(a, g->b->bin);
		if (pos == 0)
		{
			ft_pa(g);
		}
		if (pos == 1)
		{
			ft_ra(g);
			ft_pa(g);
		}
		if (pos == 2)
		{
			ft_ra(g);
			ft_ra(g);
			ft_pa(g);
		}
		if (pos == 3)
		{
			ft_rra(g);
			ft_pa(g);
		}
	}
	ft_order_stack(g);
}

void	ft_stack_five(t_game *g)
{
	ft_pb(g);
	ft_pb(g);
	ft_stack_three(g);
	ft_penultimate(g);
	// print_game(g);
	ft_ultimate(g);
}

// TODO
//  finire di fixare la logica per il 5.. lo stack three lo ordina bene, ma poi rimangono i due da spostare da b ad a mentre si ruota lo stack a