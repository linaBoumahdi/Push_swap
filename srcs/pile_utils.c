/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:23:21 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/16 12:42:34 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile *set_node(int nbr)
{
	t_pile	*a;

	a->value = nbr;
	a->idx = 0;
	a->pos = -1;
	a->target_pos = -1;
	a->cost_a = -1;
	a->cost_b = -1;
	a->next = NULL;
	a->prev = NULL;
	return(a);
}
void	add_to_pile(t_pile **a, int nbr)
{
	t_pile *node;
	t_pile *last;

	if (!a)
		return ;
	node = malloc (sizeof(t_pile));
	if (!node)
		return ;
	node = set_node(nbr);
	if (!(*a))
	{
		node->prev = NULL;
		*a = node;
	} 
	else 
	{
		last = get_last_node(*a);
		last->next = node;
		node->prev = last;
	}
}

int	is_number(char *s)
{
	int	i;

	i = 1;
	if (!(s[0] == '-' || s[0] == '+' || (s[0] >= '0' && s[0] <= '9')))
		return (1);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

static int is_repeated (t_pile *a, int nbr)
{
	if(!a)
		return(0);
	while(a)
	{
		if(a->value == nbr)
			return(1);
		a = a->next;
	}
	return(0);
}
int	is_valid(t_pile *a, long nbr)
{
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	if (is_repeated(a, nbr) == 1)
		return(1);
	return(0);
}



// #include "stdio.h"
// int main()
// {
// 	t_pile *a;
// 	a = NULL;
// 	int i = 0;
// 	while(i < 2)
// 	{
// 		add_to_pile(&a, 1);
// 		i++;
// 	}
// 	printf("Original list: \n");
//     print_list(&a);
// 	// t_pile *head = newNode(1);
//     // head->next = newNode(2);
//     // head->next->prev = head;
//     // head->next->next = newNode(3);
//     // head->next->next->prev = head->next;
//     // head->next->next->next = newNode(4);
//     // head->next->next->next->prev = head->next->next;
// 	// a = get_last_node(head);
// 	// printf("a = %d", a -> value);
// 	// printf("Original list: \n");
// 	// print_list(&head);
//     return 0;
// }

// void print_list(t_pile **a) {
//     t_pile *current = *a;  

    
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
//to test fill pile 