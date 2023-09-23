/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:35:14 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/19 16:54:38 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

int	is_numeric(char *str)
{
	if (*str == 43 || *str == 45)
		str++;
	if (!*str)
		return (0);
	while (*str)
		if (!('0' <= *str && *str++ <= '9'))
			return (0);
	return (1);
}

int	ft_atoi(t_stack *stack, const char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while ((9 <= *str && *str <= 13) || *str == 32)
		str++;
	if (*str == 45)
		sign = -1;
	if (*str == 43 || *str == 45)
		str++;
	while (48 <= *str && *str <= 57)
		res = res * 10 + *str++ - 48;
	if (res * sign < -2147483648 || res * sign > 2147483647)
		return (free_function(stack), ft_printf("Error\n"), exit(1),
			0);
	return (res * sign);
}

int	is_repeat(t_list *stack, int nbr)
{
	if (!stack)
		return (0);
	if (stack->data == nbr)
		return (1);
	return (is_repeat(stack->next, nbr));
}

int	is_sort(t_list *lst, char c, int len)
{
	while (c == 'a' && --len)
	{
		if (lst->data > lst->next->data)
			return (0);
		lst = lst->next;
	}
	while (c == 'b' && --len)
	{
		if (lst->data < lst->next->data)
			return (0);
		lst = lst->next;
	}
	return (1);
}

int	get_middle(int *pivot, t_list *lst, int len)
{
	int	*arr;
	int	tmp;

	arr = (int *)malloc(sizeof(int) * len);
	tmp = len;
	if (!arr)
		return (0);
	while (tmp--)
	{
		arr[tmp] = lst->data;
		lst = lst->next;
	}
	sort_int_tab(arr, len);
	return (*pivot = arr[len / 2], free(arr), 1);
}
