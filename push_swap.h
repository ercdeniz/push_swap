/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:34:59 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/19 15:35:00 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_list
{
	long			data;
	struct s_list	*next;
}					t_list;

typedef struct s_stack
{
	char			**str;
	t_list			*a;
	t_list			*b;
	int				split_check;
	int				size;
}					t_stack;

void				list_push(t_list **lst, int number);
int					get_content(t_list **lst);
int					list_size(t_list *lst);
void				list_clear(t_list **lst);
char				s(t_list **lst);
char				p(t_list **first, t_list **second);
char				r(t_list *lst);
char				rr(t_list *lst);

void				free_function(t_stack *stack);
int					is_numeric(char *str);
int					ft_atoi(t_stack *stack, const char *str);
int					is_repeat(t_list *stack, int nbr);
int					get_middle(int *pivot, t_list *lst, int size);
int					is_sort(t_list *lst, char c, int size);
void				sort_three(t_stack *stack, int size);
int					quick_sort_a(t_stack *stack, int size, int ra_check);

#endif
