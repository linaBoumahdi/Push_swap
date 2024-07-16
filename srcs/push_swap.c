/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:09:12 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/16 11:32:11 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_pile *a)
{
	int		pile_size;
	t_pile	*tmp;
	t_pile	*current_max;
	long	value;

	pile_size = ft_pile_size(a);
	while (pile_size > 0)
	{
		tmp = a;
		current_max = NULL;
		value = INT_MIN ;
		while (tmp)
		{
			if (tmp->idx == 0 && tmp->value >= value)
			{
				current_max = tmp;
				value = tmp->value;
			}
			tmp = tmp->next;
		}
		if (current_max)
			current_max->idx = pile_size;
		pile_size --;
	}
}
void	push_in_b(t_pile **a, t_pile **b)
{
	int		size;
	int		pushed;
	int		i;

	size = ft_pile_size(*a);
	pushed = 0;
	i = 0;
	while (pushed < (size / 2) && size >= 5)
	{
		if((*a)->idx <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		size --;
	}
}
// void	sort(t_pile **a, t_pile **b)
// {
// 	if(!is_sorted(a))
// 		basic_sort(a);
// 	while(*b)
// 	{
// 		get_position(a, b);
// 		get_target(a, b);
// 		get_cost(a, b);
// 		do_best_move(a, b);
// 	}
// 	if(!is_sorted(a))
		// get_position(a, b);
// 		final_rotation(a);
// }

