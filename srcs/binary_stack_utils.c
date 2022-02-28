/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_stack_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 22:17:49 by dbertill          #+#    #+#             */
/*   Updated: 2022/02/28 22:17:49 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_n_bits(int len)
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

char	*ft_int_to_bin(int n, int len)
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
