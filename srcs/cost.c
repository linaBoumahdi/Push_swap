/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 12:44:34 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/16 12:57:39 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_pile **a, t_pile **b)
{
	t_pile	*tmp_a;
	t_pile	*tmp_b;
	int pile_size;

	tmp_a = *a;
	tmp_b = *b;
	pile_size = ft_pile_size(tmp_a);
	while (tmp_a)
	{
		if(tmp_a->pos < pile_size &&)
		tmp_a = tmp_a->next;
	}
	pile_size = ft_pile_size(tmp_b);
	while()
}