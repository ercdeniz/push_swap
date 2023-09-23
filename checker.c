/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:52 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/23 16:51:48 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static inline int	first_part(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		s(&stack->a);
	else if (!ft_strncmp(line, "sb\n", 3))
		s(&stack->b);
	else if (!ft_strncmp(line, "ra\n", 3))
		r(stack->a);
	else if (!ft_strncmp(line, "rb\n", 3))
		r(stack->b);
	else if (!ft_strncmp(line, "rra\n", 4))
		rr(stack->a);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rr(stack->b);
	else if (!ft_strncmp(line, "pa\n", 3))
		p(&stack->b, &stack->a);
	else if (!ft_strncmp(line, "pb\n", 3))
		p(&stack->a, &stack->b);
	else
		return (0);
	return (1);
}

static inline int	second_part(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "ss\n", 3))
	{
		s(&stack->a);
		s(&stack->b);
	}
	else if (!ft_strncmp(line, "rr\n", 3))
	{
		r(stack->a);
		r(stack->b);
	}
	else if (!ft_strncmp(line, "rrr\n", 4))
	{
		rr(stack->a);
		rr(stack->b);
	}
	else
		return (0);
	return (1);
}

static inline int	checker_control(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (first_part(stack, line))
			;
		else if (second_part(stack, line))
			;
		else
		{
			ft_printf("\033[0;35mError\n");
			return (free(line), free_function(stack), 1);
		}
		free(line);
		line = get_next_line(0);
	}
	if (!is_sort(stack->a, 'a', stack->size) || list_size(stack->b))
		return (0);
	return (1);
}

static inline int	checker(t_stack *stack)
{
	int	i;
	int	num;

	i = -1;
	while (++i < stack->size)
	{
		if (!is_numeric(stack->str[i]))
		{
			if (stack->split_check)
				free_malloc(stack->str, 0);
			return (ft_printf("\033[0;35mError\n"), exit(1), 1);
		}
	}
	while (--i > -1)
	{
		num = ft_atoi(stack, stack->str[i]);
		if (is_repeat(stack->a, num))
			return (ft_printf("\033[0;35mError\n"), exit(1), 1);
		list_push(&stack->a, num);
	}
	if (checker_control(stack))
		return (ft_printf("\033[0;32mOK\n"), 0);
	return (ft_printf("\033[0;31mKO\n"), 1);
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
			return (ft_printf("\033[0;35mError\n"), 1);
		stack.split_check = 1;
		stack.size = word_count(av[1], 32);
	}
	else
	{
		stack.str = av + 1;
		stack.size = ac - 1;
	}
	return (checker(&stack), free_function(&stack), 0);
}
