#include "push_swap.h"

int		ft_bits(int	len)
{
	int	digits;

	digits = 0;
	while (len >= 1)
	{
		len = len / 2;
		digits++;
	}
	return (digits);
}

char	*ft_bin(int	n, int len)
{
	char	*bin;
	int		i;
	int		m;

	bin = ft_calloc(sizeof(char), len + 1);
	i = 1;
	while (i <= len && n > 0)
	{
		m = n % 2;
		if (m == 0)
			bin[len - i] = '0';
		else
			bin[len - i] = '1';
		n = n / 2;
		i++;
	}
	while (i <= len)
	{
		bin[len - i] = '0';
		i++;
	}
	return (bin);
}

int	ft_add_stack(t_stack *a, int value, int len)
{
	if (!a)
	{
		a = malloc(sizeof(t_stack));
		if (!a)
			return (0);
		a->bin = ft_bin(value, len);
		a->next = NULL;
		a->prev = NULL;
	}
	else
	{
		while (a->next)
			a = a->next;
		a->next = malloc(sizeof(t_stack));
		if (!a)
			return (0);
		a->next->bin = ft_bin(value, len);
		a->next->prev = a;
		a->next->next = NULL;
	}
	return (1);
}

int	ft_pop_a(t_stack *a, char **av, int ac, int *arr)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 0;
		while (arr[j] != ft_atoi(av[i]))
			j++;
		if (!(ft_add_stack(a, j, ft_bits(ac - 1))))
			return (0);
		i++;
	}
	return (1);
}

t_stack	*ft_init_a(char **av, int ac, int *arr)
{
	t_stack	*new;
	int	j;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = 0;
	j = 0;
	while(arr[j] != ft_atoi(av[1]))
		j++;
	new->bin = ft_bin(j, ft_bits(ac - 1));
	new->next = NULL;
	new->prev = NULL;
	if (!(ft_pop_a(new, av, ac, arr)))
		return (NULL);
	return (new);
}

t_game	*ft_init_game(char **av, int ac, int *arr)
{
	t_game *game;

	game = (t_game*)malloc(sizeof(t_game));
	game->n_moves = 0;
	game->a = ft_init_a(av, ac, arr);
	game->b = NULL;
	return (game);
}
