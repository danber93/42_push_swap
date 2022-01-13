/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:09:47 by dbertill          #+#    #+#             */
/*   Updated: 2021/02/06 16:09:49 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;
	char		*p;
	int			lastpos;

	i = 0;
	lastpos = -1;
	p = (char *)s;
	while (p[i] != '\0')
	{
		if (p[i] == (char)c)
			lastpos = i;
		i++;
	}
	if (p[i] == (char)c)
		return (&(p[i]));
	if (lastpos == -1)
		return (NULL);
	return (&(p[lastpos]));
}
