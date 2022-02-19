#include "push_swap.h"

int		ft_n_args(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
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

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] && s1[i] == s2[i])
		i++;
	if (i == (int)ft_strlen(s1))
		return (1);
	return (0);
}

int		ft_repetions(char **av)
{
	int	i;
	int	j;
	int	n_args;

	n_args = ft_n_args(av);
	i = 1;
	while (i < n_args)
	{
		j = i + 1;
		while (j < n_args)
		{
			if (ft_strcmp(av[i], av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_bigger_maxint(char *str)
{
	int		i;
	int		sign;
	long	res;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - '0';
		i++;
		if (res > 2147483647)
			return (1);
	}
	return (0);
}

int		ft_check_valid_input(char **av)
{
	int	i;
	int	j;

	if (ft_repetions(av))
		return (0);
	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j]) || ft_isspace(av[i][j])))
				return (0);
			if ((ft_bigger_maxint(av[i])))
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
	new = (char **)malloc(sizeof(char *) * (len + 2));
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
	new[i + 1] = NULL;
	free(input);
	return new;
}

char	**ft_check_string_input(char **av)
{
	char	**input;
	int		i;

	i = 0;
	input = ft_split(av[1], ' ');
	input = ft_add_empty(input);
	return (input);
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
	if (ft_n_args(av) == 4)
		ft_stack_three(game);
	else if (ft_n_args(av) == 6)
		ft_stack_five(game);
	else
		ft_radix_sort(game);
	ft_free_game(game);
}

//  TODO:
//  se piu grande di MAXINT deve tornare errore
//  nel caso in cui venga data una stringa contenente la lista questa alla fine non viene liberata!
//  se e gia ordinato non fare niente