/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liacovel <liacovel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 16:00:50 by liacovel          #+#    #+#             */
/*   Updated: 2021/12/04 15:54:23 by liacovel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode_s{
	int value;
	struct listnode_s *next;
} listnode_t;

void	printList(listnode_t *list)
{
	printf("value = %d\n", list->value);
	while(list->next!=NULL)
	{
		list = list->next;
		printf("value = %d\n", list->value);
	}
	return;
}

// costruttore
listnode_t *new_node(int value)
{
	listnode_t *new_node = (listnode_t*)malloc(sizeof(listnode_t));
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

// insterimento in testa
listnode_t *new_head(listnode_t *list, int value)
{
	listnode_t *head = new_node(value);
	head->next = list;
	return (head);
}

// inserimento in coda
listnode_t *new_tail(listnode_t *list, int value)
{
	listnode_t *head;
	head = list;
	listnode_t *tail = new_node(value);
	while(list->next != NULL)
		list = list->next;
	list->next = new_node(value);
	return (head);
}

void	write_move(char *move)
{
	write(1, move, 2);
	return;
}

int	ft_is_sorted(listnode_t *list)
{
	while(list->next != NULL)
	{
		if (list->value > list->next->value)
		{
			return (0);
		}
		list = list->next;
	}
	return 1;
}

void	swap(listnode_t **list)
{
	int	temp;
	if ((*list)->next != NULL)
	{
		temp = (*list)->value;
		(*list)->value = (*list)->next->value;
		(*list)->next->value = temp;
	}
	return;
}

void	double_swap(listnode_t **a, listnode_t **b)
{
	swap(a);
	swap(b);
	return;
}

void	push(listnode_t **from, listnode_t **to)
{
	listnode_t *temp;
	if(*from == NULL)
		return;
	temp = (*from)->next;
	(*to) = new_head(*to, (*from)->value);
	(*from) = temp;
	// printf("vediamo il from\n");
	// printList(*from);
}

void	rotate(listnode_t **list)
{
	listnode_t *temp;
	int value;
	
	value = (*list)->value;
	temp = (*list)->next;
	free(list);
	(*list) = new_tail(temp, value);
}

void	double_rotate(listnode_t **a, listnode_t **b)
{
	rotate(a);
	rotate(b);
	return;
}

void	reverse_rotate(listnode_t **list)
{
	listnode_t *iterator;
	listnode_t *head;
	listnode_t *new_tail;
	
	head = *list;
	iterator = *list;
	while (iterator->next != NULL)
	{
		new_tail = iterator;
		iterator = iterator->next;
	}
	new_tail->next = NULL;
	iterator->next = head;
	*list = iterator;
}

void	double_rev_rotate(listnode_t **a, listnode_t **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	return;
}

int	main(void)
{
	listnode_t **appoggio;
	listnode_t **list;
	
	// il numero dipenderá dagli args ricevuti
	appoggio = (listnode_t**)malloc(sizeof(listnode_t*) * 1000);
	list = (listnode_t**)malloc(sizeof(listnode_t*) * 1000);
	(*list) = new_node(8);
	(*list)->next = new_node(10);
	(*appoggio) = new_node(4);
	(*appoggio)->next = new_node(30);
	(*list)->next->next = new_node(1);
	//swap(list);
	//printList(list);
	// if(ft_is_sorted(list))
	// {
	// 	printf("la lista é ordinata\n");
	// }
	// printf("sorted = %d\n", ft_is_sorted(list));
	printf("ecco la lista prima\n");
	printList(*list);
	// swap(list);
	// printf("ecco il from\n");
	// printList(appoggio);
	// push(appoggio, list);
	// reverse_rotate(list);
	double_rev_rotate(list, appoggio);
	printf("ecco la lista dopo\n");
	printList(*list);
	// printf("ecco la lista appoggio dopo\n");
	// printList(*appoggio);
}