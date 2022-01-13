/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:06:52 by dbertill          #+#    #+#             */
/*   Updated: 2022/01/13 16:55:02 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	*str2;

	str = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (str2 < str)
		while (++i <= len)
			str[len - i] = str2[len - i];
	else
		while (len-- > 0)
			*(str++) = *(str2++);
	return (dst);
}
