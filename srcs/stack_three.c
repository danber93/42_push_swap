#include "push_swap.h"

int	ft_s3_is_bigger(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (s1[i] == '1' && s2[0] == '0')
			return (1);
		i++;
	}
	return (0);
}

/* g m p */
int		ft_case_1(t_game *g)
{
	t_stack	*a;

	a = g->a;
	if (ft_s3_is_bigger(a->bin, a->next->bin)
		&& !(ft_s3_is_bigger(a->bin, a->next->next->bin)))
		return (1);
	return (0);
}

int	ft_case_2(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_s3_is_bigger(a->bin, a->next->bin)
		&& ft_s3_is_bigger(a->bin, a->next->next->bin)
		&& ft_s3_is_bigger(a->next->bin, a->next->next->bin))
		return (1);
	return (0);
}

int	ft_case_3(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (ft_s3_is_bigger(a->bin, a->next->bin)
		&& ft_s3_is_bigger(a->bin, a->next->next->bin)
		&& !(ft_s3_is_bigger(a->next->bin, a->next->next->bin)))
		return (1);
	return (0);
}

int	ft_case_4(t_game *g)
{
	t_stack *a;

	a = g->a;
	if (!(ft_s3_is_bigger(a->bin, a->next->bin))
		&& ft_s3_is_bigger(a->next->bin, a->next->next->bin)
		&& !(ft_s3_is_bigger(a->bin, a->next->next->bin)))
		return (1);
	return (0);
}

/* ci sono cinque casi quindi dobbiamo prenderli in considerazione */
void	ft_stack_three(t_game *g)
{
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