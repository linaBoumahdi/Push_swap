/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:12:17 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/18 13:28:23 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **a)
{
	t_pile	*tmp;

	if (!a || !*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->prev = NULL;
	if (tmp->next)
		tmp->next->prev = tmp;
	(*a)->next = tmp;
	tmp->prev = *a;
}
// void swap(t_pile **a) {
//     if (!*a || !(*a)->next) return;
//     t_pile *first = *a;
//     t_pile *second = first->next;
//     first->next = second->next;
//     if (second->next)
//         second->next->prev = first;
//     second->next = first;
//     second->prev = first->prev;
//     first->prev = second;
//     *a = second;
// }

void	sa(t_pile **a)
{
	swap(a);
	write(1,"sa\n", 3);
}

void	sb(t_pile **b)
{
	swap(b);
	write(1,"sb\n", 3);
}

// void printList(t_pile* head) {make 
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
// t_pile *newNode(int data) {
//     t_pile *temp = malloc(sizeof(t_pile));
//     temp->value = data;
//     temp->prev = NULL;
//     temp->next = NULL;
//     return temp;
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

//     swap(&head);

//     printf("After swap: \n");
//     printList(head);

//     return 0;
// }