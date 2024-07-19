/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 14:29:47 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/19 12:36:06 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	highest_value(t_pile *a)
{
	t_pile	*tmp;
	int		highest;

	tmp = a;
	highest = tmp->value;
	while (tmp)
	{
		if (tmp->value > highest)
			highest = tmp->value;
		tmp = tmp->next;
	}
	return (highest);
}

void	basic_sort(t_pile **a)
{
	int		highest;
	t_pile	*tmp;

	tmp = *a;
	if (is_sorted(*a))
		return ;
	highest = highest_value(*a);
	if (tmp->next->value == highest)
		rra(a);
	else if (tmp->value == highest)
		ra(a);
	if (!is_sorted(*a))
		sa(a);
}