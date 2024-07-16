/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:15:28 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/15 13:13:39 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void printList(t_pile* head) {
    t_pile* current = head;
    while (current != NULL) {
        printf("Node %d: ", current->value);
        if (current->prev)
            printf("Prev = %d, ", current->prev->value);
        else
            printf("Prev = NULL, ");
        if (current->next)
            printf("Next = %d\n", current->next->value);
        else
            printf("Next = NULL\n");
        current = current->next;
    }
}
void	push_swap(t_pile **a, t_pile **b)
{
	int	len;

	len = ft_pile_len(*a);
	if(len == 2)
		sa(a);
	if(len == 3)
		basic_sort(a);
	else
	{
		//initialize pile(target/index/pos)
		set_index(a);
		push_in_b(a, b);
		sort(a, b);
		// if(!is_sorted(a))
		// 	ra(a);		
	}
}

int	main(int ac, char **av)
{
	t_pile	*a;
	t_pile	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || !(av[1][0]))
		return (0);
	if (ac == 2)
		av = ft_split(av[1], 32);
	fill_pile(&a, av, ac);
	if(!is_sorted(a))
		// push_swap(&a, &b);
	//printList(a);
	free_pile(a);
	if(ac == 2)
		free_av(av);
	
}