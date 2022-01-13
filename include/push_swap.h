#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_stack
{
	int				num;
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

#endif