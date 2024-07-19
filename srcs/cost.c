/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:44:34 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/19 12:26:13 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	n_abs(int nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

void	push_cost(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *a;
	tmp_b = *b;
	size_a = ft_pile_size(tmp_a);
	size_b = ft_pile_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	best_move(t_pile **a, t_pile **b)
{
	long	best_cost;
	t_pile	*tmp;
	t_best	best;

	tmp = *b;
	best_cost = LONG_MAX;
	while (tmp)
	{
		if (best_cost > n_abs(tmp->cost_a) + n_abs(tmp->cost_b))
		{
			best_cost = n_abs(tmp->cost_a) + n_abs(tmp->cost_b);
			best.cost_a = tmp->cost_a;
			best.cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_best_move(a, b, &best);
}

void	do_best_move(t_pile **a, t_pile **b, t_best *best)
{
	if (best->cost_a > 0 && best->cost_b > 0)
		do_rotate(a, b, best);
	if (best->cost_a < 0 && best->cost_b < 0)
		do_rev_rotate(a, b, best);
	do_rotate_a(a, best);
	do_rotate_b(b, best);
}
