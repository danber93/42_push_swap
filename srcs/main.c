#include "push_swap.h"

int	ft_populate_stack(t_stack *stck, char** av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		stck->num = ft_atoi(av[i++]);
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

t_stack	*ft_init_stack(char **av, int is_a)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->num = 0;
	new->next = NULL;
	new->prev = NULL;
	if (is_a)
		if (!ft_populate_stack(new, av))
			return (0);
	return (new);
}

t_game	*ft_init_game(char **av)
{
	t_game *game;

	game = (t_game*)malloc(sizeof(t_game));
	game->n_moves = 0;
	game->a = ft_init_stack(av, 1);
	game->b = ft_init_stack(av, 0);
	return (game);
}

int	main(int ac, char** av)
{
	int		i;
	t_game *game;

	i = 0;
	game = ft_init_game(av);
	while (i < ac)
	{
		printf("%s \n",av[i++]);
	}
}
