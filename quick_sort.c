/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 13:33:31 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/23 13:43:10 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack, int size)
{
	int	a;
	int	b;
	int	c;

	if (size == 2 && stack->a->data > stack->a->next->data)
		ft_printf("sa%c", s(&stack->a));
	if (size == 3)
	{
		a = stack->a->data;
		b = stack->a->next->data;
		c = stack->a->next->next->data;
		if (a < b && b < c)
			return ;
		if (a < b && a > c)
			return (ft_printf("rra%c", rr(stack->a)), sort_three(stack, 3));
		if (a > c && c > b)
			return (ft_printf("ra%c", r(stack->a)), sort_three(stack, 3));
		return (ft_printf("sa%c", s(&stack->a)), sort_three(stack, 3));
	}
}

void	quick_sort_three_a(t_list **lst, int size)
{
	while (size == 2 || !is_sort(*lst, 'a', 3))
	{
		if ((*lst)->data > (*lst)->next->data)
			ft_printf("sa%c", s(lst));
		else if (size == 3)
			ft_printf("ra%csa%crra%c", r(*lst), s(lst), rr(*lst));
		if (size == 2)
			return ;
	}
}

void	quick_sort_three_b(t_stack *stack, int size)
{
	if (size == 1)
		ft_printf("pa%c", p(&stack->b, &stack->a));
	else if (size == 2)
	{
		if (stack->b->data < stack->b->next->data)
			ft_printf("sb%c", s(&stack->b));
		while (size--)
			ft_printf("pa%c", p(&stack->b, &stack->a));
	}
	else if (size == 3)
	{
		while (size)
		{
			if (size == 1 && stack->a->data > stack->a->next->data)
				ft_printf("sa%c", s(&stack->a));
			else if (size == 1
				|| (size >= 2 && stack->b->data > stack->b->next->data)
				|| (size == 3 && stack->b->data > stack->b->next->next->data))
				ft_printf("pa%c", p(&stack->b, &stack->a) * (--size != -1));
			else
				ft_printf("sb%c", s(&stack->b));
		}
	}
	return ;
}

int	quick_sort_b(t_stack *stack, int size, int rb_check)
{
	int	pivot;
	int	len;

	if (is_sort(stack->b, 'b', size))
		while (size--)
			ft_printf("pa%c", p(&stack->b, &stack->a));
	if (size <= 3)
		return (quick_sort_three_b(stack, size), 1);
	len = size;
	if (!get_middle(&pivot, stack->b, size))
		return (0);
	while (size != len / 2)
	{
		if (stack->b->data >= pivot && size--)
			ft_printf("pa%c", p(&stack->b, &stack->a));
		else if (++rb_check)
			ft_printf("rb%c", r(stack->b));
	}
	while (len / 2 != list_size(stack->b) && rb_check--)
		ft_printf("rrb%c", rr(stack->b));
	return (quick_sort_a(stack, len / 2 + len % 2, 0)
		&& quick_sort_b(stack, len / 2, 0));
}

int	quick_sort_a(t_stack *stack, int size, int ra_check)
{
	int	pivot;
	int	len;

	if (is_sort(stack->a, 'a', size))
		return (1);
	len = size;
	if (size <= 3)
	{
		if (list_size(stack->a) == 3)
			return (sort_three(stack, 3), 1);
		return (quick_sort_three_a(&stack->a, size), 1);
	}
	if (!get_middle(&pivot, stack->a, size))
		return (0);
	while (size != len / 2 + len % 2)
	{
		if (stack->a->data < pivot && size--)
			ft_printf("pb%c", p(&stack->a, &stack->b));
		else if (++ra_check)
			ft_printf("ra%c", r(stack->a));
	}
	while (len / 2 + len % 2 != list_size(stack->a) && ra_check--)
		ft_printf("rra%c", rr(stack->a));
	return (quick_sort_a(stack, len / 2 + len % 2, 0)
		&& quick_sort_b(stack, len / 2, 0));
}
