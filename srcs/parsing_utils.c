/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:53:32 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/13 12:38:20 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sign(char *str)
{
	int i;

	i = 0;
	if (str[i + 1] >= '0' && str[i + 1] <= '9')
	{
			if (str[i] == '-')
				return(-1);
			else 
				return (1);
	}
	return(0);
}
static long ft_atol(char *str, int *flag)
{
	long	num;
	int		i;
	long	tmp;
	
	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		{
			*flag = check_sign(&str[i]);
			i++;
		}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		tmp = num;
		num = num * 10 + str[i] - '0';
		if (num < tmp)
            return (LONG_MAX);
		i++;
	}
	return (num * (*flag));
}

void	fill_pile(t_pile **a, char **av, int ac)
{
	int		i;
	long	nbr;
	int		sign;

	sign = 1;
	if (ac == 2)
		i = 0;
	else
		i = 1;
	while (av[i])
	{
		if (is_number(av[i]) == 1)
			error_input(*a, av, ac);
		nbr = ft_atol(av[i], &sign);
		if (sign == 0)
			error_input(*a, av, ac);
		if (is_valid(*a, nbr) == 1)
			error_input(*a, av, ac);
		add_to_pile(a, nbr);
		i++;
	}
} 

int	is_sorted(t_pile *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

