/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:07:26 by dbertill          #+#    #+#             */
/*   Updated: 2021/02/06 16:07:26 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	char		*p;

	i = 0;
	p = (char *)s;
	while (p[i])
		if (p[i++] == (char)c)
			return (&(p[--i]));
	if (p[i] == (char)c)
		return (&(p[i]));
	return (NULL);
}
