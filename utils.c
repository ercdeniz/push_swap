/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:35:08 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/19 15:43:11 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	list_push(t_list **lst, int number)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!lst || !new)
		return ;
	new->data = number;
	new -> next = *lst;
	*lst = new;
}

int	get_content(t_list **lst)
{
	t_list	*tmp;
	int		nbr;

	tmp = (*lst);
	nbr = tmp->data;
	free(tmp);
	*lst = (*lst)->next;
	return (nbr);
}

int	list_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void	list_clear(t_list **lst)
{
	t_list	*nbrs;

	if (!lst)
		return ;
	while (*lst)
	{
		nbrs = (*lst);
		free(nbrs);
		*lst = (*lst)->next;
	}
}

void	free_function(t_stack *stack)
{
	if (stack->split_check)
		free_malloc(stack->str, 0);
	list_clear(&stack->a);
	list_clear(&stack->b);
}
