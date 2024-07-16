/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:37:30 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/14 10:38:10 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_last_node(t_pile *a)
{
	t_pile	*last;

	if (!a)
		return (0);
	last = a;
	while (last->next)
		last = last->next;
	return (last);
}

int	ft_pile_size(t_pile *a)
{
	int	i;

	i = 1;
	if (!a)
		return (0);
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}
