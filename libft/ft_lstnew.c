/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbertill <dbertill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 16:06:21 by dbertill          #+#    #+#             */
/*   Updated: 2022/01/13 17:48:39 by dbertill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst_new;

	lst_new = malloc(sizeof(t_list *));
	if (!lst_new)
		return (0);
	lst_new->content = content;
	lst_new->next = NULL;
	return (lst_new);
}
