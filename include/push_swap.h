#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Binary tree
typedef struct s_node
{
	int	value;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct	s_stack
{
	char			*bin;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_game
{
	int		n_moves;
	t_stack	*a;
	t_stack	*b;
}	t_game;

#include <stdlib.h>
#include "libft.h"

#include <stdio.h>

/* Moves */
int	ft_swap(t_stack *stack);
int	ft_ss(t_game *game);
int	ft_pa(t_game *game);
int	ft_pb(t_game *game);
void	ft_ra(t_game *game);
void	ft_rb(t_stack *b);
void	ft_rr(t_game *game);
void	ft_rra(t_game *game);
void	ft_rrb(t_game *game);
void	ft_rrr(t_game *game);

/* Binary Tree */
t_node	*ft_init_btree(char **av);
int	*ft_pop_arr(t_node *root, int ac);
void	ft_free_btree(t_node *node);

/* Binary number */
int	ft_pop_a(t_stack *a, char **av, int ac, int *arr);
t_game	*ft_init_game(char **av, int ac, int *arr);

/* Order alg */
void	ft_order(t_game	*g);

void	print_game(t_game *g);
#endif