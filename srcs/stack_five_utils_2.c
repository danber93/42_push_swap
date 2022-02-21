#include "push_swap.h"

int	ft_is_not_consecutive(char *sa, char *sb)
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

int	ft_position(t_stack *a, char *bin)
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

int	ft_find_bin(t_game *g, char *bin)
{
	t_stack	*a;
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
