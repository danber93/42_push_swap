/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:18:08 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/21 22:18:14 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_stack
{
	char			*bin;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_game
{
	t_stack	*a;
	t_stack	*b;
}	t_game;

/* Moves */
int		ft_sa(t_game *game);
int		ft_pa(t_game *game);
int		ft_pb(t_game *game);
void	ft_ra(t_game *game);
void	ft_rra(t_game *game);

/* Binary Tree */
t_node	*ft_init_btree(char **av);
int		*ft_pop_arr(t_node *root, int ac);
void	ft_free_btree(t_node *node);

/*Binary stack */
int		ft_n_bits(int len);
char	*ft_int_to_bin(int n, int len);
int		ft_pop_a(t_stack *a, char **av, int ac, int *arr);
t_game	*ft_init_game(char **av, int ac, int *arr);

/* Order */
void	ft_radix_sort(t_game	*g);
void	ft_stack_three(t_game *g);
void	ft_stack_five(t_game *g);
void	print_game(t_game *g);
int		ft_is_bigger(char *s1, char *s2);
int		ft_is_sorted(t_stack *a);
char	*ft_find_first(t_stack *a, int bit);
void	ft_it_b(t_game *g);
int		ft_equals(char *s1, char *s2);
int		ft_biggest(t_game *g);
int		ft_smallest(t_game *g);
void	ft_penultimate_between_two(t_game *g);
void	ft_penultimate(t_game *g);
int		ft_is_not_consecutive(char *sa, char *sb);
int		ft_position(t_stack *a, char *bin);
int		ft_find_bin(t_game *g, char *bin);

/* push swap */
int		ft_n_args(char **av);
int		ft_is_bigger(char *s1, char *s2);
int		ft_is_sorted(t_stack *a);
int		ft_is_solved(t_game *g);
void	ft_free_game(t_game *g);
void	ft_print_error(void);
int		ft_strcmp(char *s1, char *s2);
int		ft_repetions(char **av);
int		ft_bigger_maxint(char *str);
int		ft_check_valid_input(char **av);

#endif
