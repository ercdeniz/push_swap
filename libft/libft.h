/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ercdeniz <ercdeniz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 15:37:13 by ercdeniz          #+#    #+#             */
/*   Updated: 2023/09/23 16:51:21 by ercdeniz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <unistd.h>

// LIBFT
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
char		*ft_strchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		**free_malloc(char **tab, size_t i);
int			word_count(char const *s, char c);
char		**ft_split(char const *s, char c);
void		sort_int_tab(int *arr, int size);

// GET_NEXT_LINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 13
# endif

char		*get_next_line(int fd);
char		*get_next_line_bonus(int fd);

// FT_PRINTF
# define DEC "0123456789"
# define HEXLOW "0123456789abcdef"
# define HEXUP "0123456789ABCDEF"

typedef struct s_printf
{
	va_list	args;
	char	f;
	int		len;
}			t_printf;

int			ft_printf(const char *s, ...);

#endif
