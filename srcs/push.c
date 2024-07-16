/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:12:01 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/15 11:47:41 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_pile **a, t_pile **b)
{
	t_pile	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = tmp->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = tmp;
	tmp->next = *b;
	*b = tmp;
}

void	pa(t_pile **a, t_pile **b)
{
	push(b, a);
	write(1,"pa\n", 3);
}

void	pb(t_pile **a, t_pile **b)
{
	push(a, b);
	write(1,"pb\n", 3);
}
// TESSTTTTTT
// t_pile *create_node(int value)
// {
// 	t_pile *new_node;

// 	new_node = malloc(sizeof(t_pile));
// 	if(!new_node)
// 		return NULL;
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	new_node->prev = NULL;
// 	return(new_node);
// }
// void print_pile(t_pile* head) {
//     t_pile* current = head;
//     while (current != NULL) {
//         printf("Node %d: ", current->value);
//         if (current->prev)
//             printf("Prev = %d, ", current->prev->value);
//         else
//             printf("Prev = NULL, ");
//         if (current->next)
//             printf("Next = %d\n", current->next->value);
//         else
//             printf("Next = NULL\n");
//         current = current->next;
//     }
// }

// void append_node(t_pile **head, int *nbr)
// {
// 	t_pile *new_node;
// 	t_pile *current = *head;
// 	int i = 0;

// 	while(i < 4)
// 	{
// 		new_node = create_node(nbr[i]);
// 		if(!new_node)
// 			return;
// 		if(*head == NULL)
// 		{	
// 			*head = new_node;
// 			current = *head;
// 		}
// 		else
// 		{
// 			while(current->next)
// 				current = current->next;
// 			current->next = new_node;
// 			new_node->prev = current;
// 		}
// 		i++;
// 	}	
// }
// int main( )
// {
// 	t_pile *a = NULL;
// 	t_pile *b = create_node(10);

// 	int nbr[] = {1, 2, 3, 5};
// 	append_node(&a, nbr);
//     printf("Pile A before push:\n");
//     print_pile(a);

//     push(&a, &b);
//     printf("Pile A after push:\n");
//     print_pile(a);
//     printf("Pile B after push:\n");
//     print_pile(b);

// 	return 0;
// }