/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:00:17 by dbertill          #+#    #+#             */
/*   Updated: 2022/01/13 16:36:07 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_space(char const *s, char c)
{
	size_t	numword;
	size_t	i;

	i = 0;
	numword = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			numword += 1;
		i++;
	}
	return (numword);
}

size_t	ft_str_len_mod(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_final_split(const char *s, size_t i, size_t gest)
{
	size_t	y;
	char	*str;

	str = ft_calloc(gest + 1, sizeof(char *));
	if (!str)
		return (0);
	y = 0;
	while (y < (gest))
	{
		str[y] = s[i];
		y++;
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;
	size_t	gest;

	str = ft_calloc(ft_space(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			gest = ft_str_len_mod(&s[i], c);
			str[j] = ft_final_split(s, i, gest);
			if (!(str[j++]))
				return (0);
			i += gest;
		}
	}
	return (str);
}
