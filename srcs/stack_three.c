#include "push_swap.h"

int	ft_case_1(t_game *g)
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
	t_stack	*a;

	a = g->a;
	if (ft_is_bigger(a->bin, a->next->bin)
		&& ft_is_bigger(a->bin, a->next->next->bin)
		&& ft_is_bigger(a->next->bin, a->next->next->bin))
		return (1);
	return (0);
}

int	ft_case_3(t_game *g)
{
	t_stack	*a;

	a = g->a;
	if (ft_is_bigger(a->bin, a->next->bin)
		&& ft_is_bigger(a->bin, a->next->next->bin)
		&& !(ft_is_bigger(a->next->bin, a->next->next->bin)))
		return (1);
	return (0);
}

int	ft_case_4(t_game *g)
{
	t_stack	*a;

	a = g->a;
	if (!(ft_is_bigger(a->bin, a->next->bin))
		&& ft_is_bigger(a->next->bin, a->next->next->bin)
		&& !(ft_is_bigger(a->bin, a->next->next->bin)))
		return (1);
	return (0);
}

void	ft_stack_three(t_game *g)
{
	if (ft_is_sorted(g->a))
		return ;
	if (ft_case_1(g))
		ft_sa(g);
	else if (ft_case_2(g))
	{
		ft_sa(g);
		ft_rra(g);
	}
	else if (ft_case_3(g))
		ft_ra(g);
	else if (ft_case_4(g))
	{
		ft_sa(g);
		ft_ra(g);
	}
	else
		ft_rra(g);
}
