#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int				value;
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
int ft_pa(t_game *game);
int ft_pb(t_game *game);
void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_game *game);
void	ft_rra(t_game *game);
void	ft_rrb(t_game *game);
void	ft_rrr(t_game *game);

#endif