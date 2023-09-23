/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:35:05 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/23 17:01:52 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	s(t_list **lst)
{
	if (!*lst || !(*lst)->next)
		return (10);
	(*lst)->data = (*lst)->data + (*lst)->next->data;
	(*lst)->next->data = (*lst)->data - (*lst)->next->data;
	return ((*lst)->data = (*lst)->data - (*lst)->next->data, 10);
}

char	p(t_list **first, t_list **second)
{
	if (!*first)
		return (10);
	return (list_push(second, get_content(first)), 10);
}

char	r(t_list *lst)
{
	if (!lst)
		return (10);
	while (lst->next)
	{
		s(&lst);
		lst = lst->next;
	}
	return (10);
}

char	rr(t_list *lst)
{
	if (!lst->next)
		return (10);
	return (rr(lst->next), s(&lst), 10);
}
