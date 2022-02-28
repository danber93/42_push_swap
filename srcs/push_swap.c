/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:41 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:17:41 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	print_game(t_game *g)
// {
// 	t_stack	*a;;
// 	t_stack	*b;

// 	a = g->a;
// 	b = g->b;
// 	while (a || b)
// 	{
// 		if (a && b)
// 		{
// 			printf("%s        %s\n", a->bin, b->bin);
// 			a = a->next;
// 			b = b->next;
// 		}
// 		else if (a && !b)
// 		{
// 			printf("%s        \n", a->bin);
// 			a = a->next;
// 		}
// 		else if (!a && b)
// 		{
// 			printf("        %s\n", b->bin);
// 			b = b->next;
// 		}
// 	}
// 	printf("--       --\n");
// 	printf("a.........b\n\n");
// }

void	ft_add_empty_supp(char **input, char **new, int len)
{
	int		i;
	size_t	j;

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
}

char	**ft_add_empty(char **input)
{
	char	**new;
	int		len;

	len = 0;
	while (input[len])
		len++;
	new = (char **)malloc(sizeof(char *) * (len + 2));
	if (!new)
		return (NULL);
	new[0] = "./push_swap\0";
	ft_add_empty_supp(input, new, len);
	len = 0;
	while (input[len])
		free(input[len++]);
	free(input);
	return (new);
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

void	ft_play(char **args, int f)
{
	t_node	*root;
	int		*arr;
	t_game	*game;
	int		i;

	root = ft_init_btree(args);
	arr = ft_pop_arr(root, ft_n_args(args));
	ft_free_btree(root);
	game = ft_init_game(args, ft_n_args(args), arr);
	free(arr);
	if (!(ft_is_solved(game)))
	{
		if (ft_n_args(args) == 4)
			ft_stack_three(game);
		else if (ft_n_args(args) == 6)
			ft_stack_five(game);
		else
			ft_radix_sort(game);
	}
	if (f == 1)
	{
		i = 0;
		while (args[i])
			free(args[i++]);
		free(args);
	}
	ft_free_game(game);
}

int	main(int ac, char **av)
{
	int		i;
	int		f;
	char	**args;

	i = 1;
	if (ac == 1)
		exit(0);
	f = 0;
	args = av;
	if (ac == 2)
	{
		args = ft_check_string_input(av);
		if (!args)
			ft_print_error();
		f = 1;
	}
	if (!(ft_check_valid_input(args)))
		ft_print_error();
	ft_play(args, f);
}
