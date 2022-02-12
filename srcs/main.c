#include "push_swap.h"

// int	ft_populate_stack(t_stack *stck, char** av)
// {
// 	int	i;

// 	i = 1;
// 	while (av[i])
// 	{
// 		stck->value = ft_atoi(av[i++]);
// 		if (av[i])
// 		{
// 			stck->next = malloc(sizeof(t_stack));
// 			if (!(stck->next))
// 				return (0);
// 			stck->next->prev = stck;
// 			stck->next->next = NULL;
// 			stck = stck->next;
// 		}
// 	}
// 	return (1);
// }

// t_stack	*ft_init_a(char **av)
// {
// 	t_stack	*new;

// 	new = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new)
// 		return (0);
// 	new->value = 0;
// 	new->next = NULL;
// 	new->prev = NULL;
// 	if (!ft_populate_stack(new, av))
// 		return (0);
// 	return (new);
// }

// t_game	*ft_init_game(char **av)
// {
// 	t_game *game;

// 	game = (t_game*)malloc(sizeof(t_game));
// 	game->n_moves = 0;
// 	game->a = ft_init_a(av);
// 	game->b = NULL;
// 	return (game);
// }

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

int is_sorted(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while(a->next)
	{
		if (a->value <= a->next->value)
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	is_solved(t_game *g)
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
	// ft_pb(game);
	// print_game(game);
	// ft_rrr(game);
	// print_game(game);
	// 87 -487 781 -100 101 0 1
}

//  TODO:
//  1. cambiare le mosse perche devono spostare le stringhe (e non gli interi)
//  2. cambiare t_stack e togliere il value (perche adesso è una stringa)
//  3. implementare la logica delle mosse sui bit.