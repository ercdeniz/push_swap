/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:32:19 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/23 16:51:35 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static inline void	push_swap(t_stack *stack)
{
	int	i;
	int	nbr;

	i = -1;
	while (++i < stack->size)
	{
		if (!is_numeric(stack->str[i]))
		{
			if (stack->split_check)
				free_malloc(stack->str, 0);
			return (ft_printf("Error\n"), exit(1));
		}
	}
	while (--i > -1)
	{
		nbr = ft_atoi(stack, stack->str[i]);
		if (is_repeat(stack->a, nbr))
			return (ft_printf("Error\n"), free_function(stack), exit(1));
		list_push(&stack->a, nbr);
	}
	if (2 <= stack->size && stack->size <= 3)
		sort_three(stack, stack->size);
	else if (stack->size > 3)
		quick_sort_a(stack, stack->size, 0);
}

int	main(int ac, char **av)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	stack.split_check = 0;
	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		stack.str = ft_split(av[1], 32);
		if (!stack.str)
			return (ft_printf("Error\n"), 1);
		stack.split_check = 1;
		stack.size = word_count(av[1], 32);
	}
	else
	{
		stack.str = av + 1;
		stack.size = ac - 1;
	}
	return (push_swap(&stack), free_function(&stack), 0);
}
