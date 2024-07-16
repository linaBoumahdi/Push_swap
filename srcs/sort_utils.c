/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:08:15 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/15 20:07:41 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void get_position(t_pile **a, t_pile **b)
{
	int	i;
	t_pile *tmp1;
	t_pile *tmp2;

	tmp1 = *a;
	tmp2 = *b;
	i = 0;
	while(tmp1)
	{
		tmp1->pos = i;
		tmp1 = tmp1->next;
		i++;
	}
	i = 0;
	while(tmp2)
	{
		tmp2->pos = i;
		tmp2 = tmp2->next;
		i++;
	}
}
// void	get_lowest_index_pos(t_pile **a, int *lowest_pos)
// {
// 	t_pile *tmp;
// 	int lowest_idx;

// 	tmp = *a;
// 	lowest_idx = 0;
// 	while(tmp)
// 	{
// 		if(tmp->idx >= lowest_idx)
// 		{
// 			*lowest_pos = tmp->pos;
// 			lowest_idx = tmp->idx;
// 		}
// 		tmp = tmp->next;
// 	}
// }

// void	get_target_pos(t_pile **a, int idx_b, int  *target_pos)
// {
// 	t_pile *tmp;
// 	long target_idx;

// 	target_idx = LONG_MAX;
// 	tmp = *a;
// 	while(tmp)
// 	{
// 		if(idx_b < tmp->idx && target_idx >= tmp->idx)
// 		{
// 			*target_pos = tmp->pos;
// 			target_idx = tmp->idx;
// 		}
// 		tmp = tmp->next;
// 	}
// 	if(target_idx == LONG_MAX)
// 		get_lowest_index_pos(a, target_pos);
// }
void	get_target(t_pile **a, t_pile **b)
{
	int	target_pos;
	t_pile *tmp;

	tmp = *b;
	target_pos = 0;
	while(tmp)
	{
		target_pos = get_target_pos(a, tmp->idx, INT_MAX, target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp -> next;
	}
}

//TTTTTTESSTSTTT


int	get_lowest_index_pos(t_pile **stack)
{
	t_pile	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	// get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->idx < lowest_index)
		{
			lowest_index = tmp->idx;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

 int	get_target_pos(t_pile **a, int b_idx,
								int target_idx, int target_pos)
{
	t_pile	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx > b_idx && tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->idx < target_idx)
		{
			target_idx = tmp_a->idx;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

// void	get_target_position(t_pile **a, t_pile **b)
// {
// 	t_pile	*tmp_b;
// 	int		target_pos;

// 	tmp_b = *b;
// 	get_position(a, b);
// 	target_pos = 0;
// 	while (tmp_b)
// 	{
// 		target_pos = get_target(a, tmp_b->idx, INT_MAX, target_pos);
// 		tmp_b->target_pos = target_pos;
// 		tmp_b = tmp_b->next;
// 	}
// }