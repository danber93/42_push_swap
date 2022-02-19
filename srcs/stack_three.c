#include "push_swap.h"

/* g m p */
int		ft_case_1(t_game *g)
{
	t_stack	*a;

	a = g->a;
	if (ft_is_bigger(a->bin, a->next->bin)
		&& !(ft_is_bigger(a->bin, a->next->next->bin)))
		return (1);
	return (0);
}

int	ft_case_2(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_is_bigger(a->bin, a->next->bin)
		&& ft_is_bigger(a->bin, a->next->next->bin)
		&& ft_is_bigger(a->next->bin, a->next->next->bin))
		return (1);
	return (0);
}

int	ft_case_3(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_is_bigger(a->bin, a->next->bin)
		&& ft_is_bigger(a->bin, a->next->next->bin)
		&& !(ft_is_bigger(a->next->bin, a->next->next->bin)))
		return (1);
	return (0);
}

int	ft_case_4(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (!(ft_is_bigger(a->bin, a->next->bin))
		&& ft_is_bigger(a->next->bin, a->next->next->bin)
		&& !(ft_is_bigger(a->bin, a->next->next->bin)))
		return (1);
	return (0);
}

void	ft_print_a(t_stack *a)
{
	t_stack *s;

	s = a;
	printf("PRINT A\n");
	while (a)
	{
		printf("%s\n", a->bin);
		a = a->next;
	}
	printf("#######\n");
}

void	ft_stack_three(t_game *g)
{
	// ft_print_a(g->a);
	if (ft_is_sorted(g->a))
	{
		printf("is sorted.\n");
		return;
	}
	if (ft_case_1(g))
	{
		ft_sa(g);
		ft_putstr_fd("sa\n\0", 1);
	}
	else if (ft_case_2(g))
	{
		ft_sa(g);
		ft_putstr_fd("sa\n\0", 1);
		ft_rra(g);
		ft_putstr_fd("rra\n\0", 1);
	}
	else if (ft_case_3(g))
	{
		ft_ra(g);
		ft_putstr_fd("ra\n\0", 1);
	}
	else if (ft_case_4(g))
	{
		ft_sa(g);
		ft_putstr_fd("sa\n\0", 1);
		ft_ra(g);
		ft_putstr_fd("ra\n\0", 1);
	}
	else
	{
		ft_rra(g);
		ft_putstr_fd("rra\n\0", 1);
	}
}