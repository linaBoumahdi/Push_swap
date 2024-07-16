/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:12:12 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/13 12:44:08 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_pile **a)
{
	t_pile	*last;
	int		len;

	last = get_last_node(*a);
	if (!*a || !a || !(*a)->next)
		return ;
	(*a)->prev = last;
	last->next = *a;
	last->prev->next = NULL;
	*a = last;
	(*a)->prev = NULL;
}

void	rra(t_pile **a)
{
	rrotate(a);
	write(1,"rra\n", 4);
}

void	rrb(t_pile **b)
{
	rrotate(b);
	write(1,"rrb\n", 4);
}

void	rrr(t_pile **a, t_pile **b)
{
	rrotate(a);
	rrotate(b);
	write(1,"rrr\n", 4);
}
// //TEST
// t_pile *newNode(int data) {
//     t_pile *temp = malloc(sizeof(t_pile));
//     temp->value = data;
//     temp->prev = NULL;
//     temp->next = NULL;
//     return temp;
// }

// void printList(t_pile* head) {
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
// t_pile* createList(int numberOfNodes) {
//      if (numberOfNodes <= 0)
// 	  return NULL;

//    t_pile* head = newNode(1); 
// 	t_pile* current = head;

//     for (int i = 2; i <= numberOfNodes; ++i) {
//         t_pile* new_node = newNode(i);
//         new_node->prev = current;
//         current->next = new_node;
//         current = new_node;
//     }

//     return head;
// }
// int main() {
// 	int numberOfNodes = 2; 
//     t_pile* head = createList(numberOfNodes);

//     printf("Original list: \n");
//     printList(head);

//     rr(&head);

//     printf("After rotation: \n");
//     printList(head);
//     return 0;
// }
// last->prev->next = NULL;
	// last->next = *a;
	// (*a)->prev = last;
	// *a = last;
	// (*a)->prev = NULL;