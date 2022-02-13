#include "push_swap.h"

void	print_game(t_game *g)
{
	t_stack	*a;;
	t_stack	*b;

	a = g->a;
	b = g->b;
	while (a || b)
	{
		if (a && b)
		{
			// printf("%i        %i\n", a->value, b->value);
			printf("%s        %s\n", a->bin, b->bin);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			// printf("%i         \n", a->value);
			printf("%s        \n", a->bin);
			a = a->next;
		}
		else if (!a && b)
		{
			// printf("         %i\n", b->value);
			printf("        %s\n", b->bin);
			b = b->next;
		}
	}
	printf("--       --\n");
	printf("a.........b\n\n");
}

int	ft_is_smaller(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while(i < len - 1)
	{
		if (s1[len - i] == '1' && s2[len - i] == '0')
			if (s1[len - i + 1] == '1' && s2[len - i + 1] == '0')
				return (0);
		i++;
	}
	return (1);
}

int is_sorted(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while(a->next)
	{
		if (ft_is_smaller(a->bin, a->next->bin))
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_is_solved(t_game *g)
{
	if (g->a)
		if (is_sorted(g->a) && !(g->b))
			return (1);
	return (0);
}

int	main(int ac, char** av)
{
	int		i;
	int		*arr;
	t_game	*game;
	t_node	*root;

	i = 1;
	root = ft_init_btree(av);
	arr = ft_pop_arr(root, ac);
	game = ft_init_game(av, ac, arr);
	print_game(game);
	// ft_pb(game);
	// // ft_pb(game);
	// print_game(game);
	// ft_pa(game);
	// print_game(game);
	// ft_pa(game);
	// print_game(game);
	// ft_rrr(game);
	// print_game(game);
	// 87 -487 781 -100 101 0 1
	// printf("Is sorted? = %i\n", ft_is_solved(game));

	ft_order(game);
	print_game(game);
}

//  TODO:
//  2. implementare la logica delle mosse sui bit.