#include "push_swap.h"

int	ft_populate_stack(t_stack *stck, char** av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		stck->value = ft_atoi(av[i++]);
		if (av[i])
		{
			stck->next = malloc(sizeof(t_stack));
			if (!(stck->next))
				return (0);
			stck->next->prev = stck;
			stck->next->next = NULL;
			stck = stck->next;
		}
	}
	return (1);
}

t_stack	*ft_init_a(char **av)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = 0;
	new->next = NULL;
	new->prev = NULL;
	if (!ft_populate_stack(new, av))
		return (0);
	return (new);
}

t_game	*ft_init_game(char **av)
{
	t_game *game;

	game = (t_game*)malloc(sizeof(t_game));
	game->n_moves = 0;
	game->a = ft_init_a(av);
	game->b = NULL;
	return (game);
}

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
			printf("%i        %i\n", a->value, b->value);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("%i         \n", a->value);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("         %i\n", b->value);
			b = b->next;
		}
	}
	printf("--       --\n");
	printf("a.........b\n\n");
}

int	main(int ac, char** av)
{
	int		i;
	t_game	*game;
	t_stack	*stack;

	i = 1;
	game = ft_init_game(av);
	stack = game->a;
	printf("ac = %i \n\n", ac);
	while (i < ac)
	{
		i++;
		stack = stack->next;
	}
	print_game(game);
	// ft_ra(game->a);
	// ft_swap(game->a);  OK
	//  ft_ss(game); OK con b vuota
	ft_pb(game);
	// print_game(game);
	ft_pb(game);
	print_game(game);
	// // ft_rb(game->b);
	// print_game(game);
	// ft_rr(game);
	// print_game(game);
	ft_rrr(game);
	print_game(game);
}
