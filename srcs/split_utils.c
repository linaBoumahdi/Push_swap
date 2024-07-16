/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:38:04 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/11 11:40:52 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_arrays(const char *s, char c)
{
	int	count;

	count = 0;
	if (s[0] && s[0] != c)
		count++;
	while (*s)
		while (*s && *s++ == c)
			if (*s && *s != c)
				count++;
	return (count);
}

static size_t	ft_len(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_print_str(const char **str, char c)
{
	char	*a;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	while (**str == c)
		(*str)++;
	a = malloc(ft_len(*str, c) + 1);
	if (!a)
		return (NULL);
	while (*str && **str && **str != c)
	{
		a[i++] = **str;
		(*str)++;
	}
	a[i] = '\0';
	return (a);
}

static char	**ft_free_split(char **str, int a)
{
	int	i;

	i = 0;
	while (i < a)
		free (str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		count;
	int		a;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	count = ft_count_arrays(s, c) + 1;
	res = malloc((count) * sizeof(char *));
	if (!res)
		return (NULL);
	while (count-- > 1)
	{
		res[i] = ft_print_str(&s, c);
		if (!res[i])
			return (ft_free_split(res, i));
		i++;
	}
	res[i] = NULL;
	return (res);
}