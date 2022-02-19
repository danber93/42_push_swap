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
			printf("%s        %s\n", a->bin, b->bin);
			a = a->next;
			b = b->next;
		}
		else if (a && !b)
		{
			printf("%s        \n", a->bin);
			a = a->next;
		}
		else if (!a && b)
		{
			printf("        %s\n", b->bin);
			b = b->next;
		}
	}
	printf("--       --\n");
	printf("a.........b\n\n");
}

int	ft_is_bigger(char *s1, char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (s1[i] == '1' && s2[i] == '0')
			return (1);
		if (s1[i] == '0' && s2[i] == '1')
			return (0);
		i++;
	}
	return (0);
}

int ft_is_sorted(t_stack *a)
{
	t_stack *tmp;

	tmp = a;
	while(a->next)
	{
		if (!(ft_is_bigger(a->bin, a->next->bin)))
			a = a->next;
		else
			return (0);
	}
	return (1);
}

int	ft_is_solved(t_game *g)
{
	if (g->a)
		if (ft_is_sorted(g->a) && !(g->b))
			return (1);
	return (0);
}

void	ft_free_game(t_game *g)
{
	t_stack	*a;
	t_stack	*b;

	a = g->a;
	while(a)
	{
		free(a->bin);
		g->a = a->next;
		free(a);
		a = g->a;
	}
	b = g->b;
	while(b)
	{
		free(b->bin);
		g->b = b->next;
		free(b);
		b = g->b;
	}
	free(a);
	free(b);
	free(g);
}

void	ft_print_error()
{
	ft_putstr_fd("Error\n\0", 1);
	exit(0);
}

int		ft_check_valid_input(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || ft_isspace(av[i][j])))
				return (0);
			if (ft_strlen(av[i]) > 10 || ft_atoi(av[i]) > 2147483647)
				ft_print_error();
			j++;
		}
		i++;
	}
	return (1);
}

char	**ft_add_empty(char **input)
{
	char	**new;
	int		i;
	size_t		j;
	int		len;

	len = 0;
	while (input[len])
		len++;
	new = (char **)malloc(sizeof(char *) * (len + 1));
	if (!new)
		return (NULL);
	new[0] = "./push_swap\0";
	i = 0;
	while (i < len)
	{
		new[i + 1] = ft_calloc(sizeof(char), (len + 1));
		j = 0;
		while (j < ft_strlen(input[i]))
		{
			new[i + 1][j] = input[i][j];
			j++;
		}
		i++;
	}
	free(input);
	return new;
}

char	**ft_check_string_input(char **av)
{
	char	**input;
	int		i;

	if (!(ft_check_valid_input(av)))
		return (NULL);
	i = 0;
	while(av[1][i])
	{
		if (!(ft_isspace(av[1][i])))
			return (av);
		i++;
	}
	input = ft_split(av[1], ' ');
	input = ft_add_empty(input);
	return (input);
}

int		ft_n_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	main(int ac, char** av)
{
	int		i;
	t_node	*root;
	int		*arr;
	t_game	*game;

	i = 1;
	if (ac == 1)
		exit(0);
	if (ac == 2)
	{
		av = ft_check_string_input(av);
		if (!av)
			ft_print_error();
	}
	if (!(ft_check_valid_input(av)))
		ft_print_error();
	root = ft_init_btree(av);
	arr = ft_pop_arr(root, ft_n_args(av));
	ft_free_btree(root);
	game = ft_init_game(av, ft_n_args(av), arr);
	free(arr);
	// print_game(game);
	if (ft_n_args(av) == 4)
		ft_stack_three(game);
	else if (ft_n_args(av) == 6)
		ft_stack_five(game);
	else
		ft_radix_sort(game);
	// print_game(game);
	ft_free_game(game);
}

//  TODO:
//  se piu grande di MAXINT deve tornare errore
//  nel caso in cui venga data una stringa contenente la lista questa alla fine non viene liberata!
//  se e gia ordinato non fare niente