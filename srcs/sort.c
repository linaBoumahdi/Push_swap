/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:08:15 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/18 17:31:43 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	get_position(t_pile **a, t_pile **b)
{
	int		i;
	t_pile	*tmp1;
	t_pile	*tmp2;

	tmp1 = *a;
	tmp2 = *b;
	i = 0;
	while (tmp1)
	{
		tmp1->pos = i;
		tmp1 = tmp1->next;
		i++;
	}
	i = 0;
	while (tmp2)
	{
		tmp2->pos = i;
		tmp2 = tmp2->next;
		i++;
	}
}

int	get_lowest_index_pos(t_pile **a)
{
	t_pile	*tmp;
	long	lowest_idx;
	int		lowest_pos;

	tmp = *a;
	lowest_idx = LONG_MAX;
	lowest_pos = -1;
	while (tmp)
	{
		if (tmp->idx < lowest_idx)
		{
			lowest_idx = tmp->idx;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	get_target(t_pile **a, int idx_b, int target_pos)
{
	t_pile	*tmp;
	long	target_idx;

	target_idx = LONG_MAX;
	tmp = *a;
	while (tmp)
	{
		if(idx_b < tmp->idx && target_idx >= tmp->idx)
		{
			target_pos = tmp->pos;
			target_idx = tmp->idx;
		}
		tmp = tmp->next;
	}
	if (target_idx == LONG_MAX)
		target_pos = get_lowest_index_pos(a);
	return(target_pos);
}

void	get_target_pos(t_pile **a, t_pile **b)
{
	int		target_pos;
	t_pile	*tmp;

	tmp = *b;
	target_pos = 0;
	while (tmp)
	{
		target_pos = get_target(a, tmp->idx, target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp -> next;
	}
}
