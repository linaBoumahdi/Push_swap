/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:04:58 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/19 12:38:53 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_pile **a, t_pile **b, t_best *best)
{
	while (best->cost_a > 0 && best->cost_b > 0)
	{
		rr(a, b);
		(best->cost_b)--;
		(best->cost_a)--;
	}
}

void	do_rev_rotate(t_pile **a, t_pile **b, t_best *best)
{
	while (best->cost_a < 0 && best->cost_b < 0)
	{
		rrr(a, b);
		(best->cost_a)++;
		(best->cost_b)++;
	}
}

void	do_rotate_a(t_pile **a, t_best *best)
{
	if (best->cost_a > 0)
	{
		while (best->cost_a > 0)
		{
			ra(a);
			(best->cost_a)--;
		}
	}
	else if (best->cost_a < 0)
	{
		while (best->cost_a < 0)
		{
			rra(a);
			(best->cost_a)++;
		}
	}
}

void	do_rotate_b(t_pile **a, t_best *best)
{
	if (best->cost_b > 0)
	{
		while (best->cost_b > 0)
		{
			rb(a);
			(best->cost_b)--;
		}
	}
	else if (best->cost_b < 0)
	{
		while (best->cost_b < 0)
		{
			rrb(a);
			(best->cost_b)++;
		}
	}
}

void	final_rotation(t_pile **a)
{
	int	smallest_pos;
	int	size;

	smallest_pos = get_lowest_index_pos(a);
	size = ft_pile_size(*a);
	if (smallest_pos <= size / 2)
	{
		while (smallest_pos > 0)
		{
			ra(a);
			smallest_pos --;
		}
	}
	else
	{
		while (smallest_pos < size)
		{
			rra(a);
			smallest_pos ++;
		}
	}
}
