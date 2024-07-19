/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:12:15 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/18 13:27:58 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile **a)
{
	t_pile	*last;

	if (!*a || !a || !(*a)->next)
		return ;
	last = get_last_node(*a);
	(*a)->prev = last;
	last->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last->next->next = NULL;
}
// void rotate(t_pile **a) {
//     if (!*a || !(*a)->next) return;
//     t_pile *tmp = *a;
//     *a = (*a)->next;
//     (*a)->prev = NULL;
//     while (tmp->next) {
//         tmp = tmp->next;
//     }
//     tmp->next = (*a)->prev;
//     (*a)->prev->next = NULL;
//     (*a)->prev->prev = tmp;
// }
void	ra(t_pile **a)
{
	rotate(a);
	write(1,"ra\n", 3);
}

void	rb(t_pile **b)
{
	rotate(b);
	write(1,"rb\n", 3);
}

void	rr(t_pile **a, t_pile **b)
{
	rotate(a);
	rotate(b);
	write(1,"rr\n", 3);
}

// t_pile *newNode(int data) {
//     t_pile *temp = (t_pile *)malloc(sizeof(t_pile));
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

// int main() {
//     t_pile *head = newNode(1);
//     head->next = newNode(2);
//     head->next->prev = head;
//     head->next->next = newNode(3);
//     head->next->next->prev = head->next;
//     head->next->next->next = newNode(4);
//     head->next->next->next->prev = head->next->next;

//     printf("Original list: \n");
//     printList(head);

//     rotate(&head);

//     printf("After rotation: \n");
//     printList(head);

//     return 0;
// }