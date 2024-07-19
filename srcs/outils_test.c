

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


// Function to create a new node
t_pile *create_node(int value) {
    t_pile *new_node = (t_pile *)malloc(sizeof(t_pile));
    new_node->value = value;
    new_node->idx = 0;
	new_node->target_pos = -1;
	new_node->pos = 0;
    new_node->next = NULL;
    return new_node;
}

// Function to append a node to the list
void append_node(t_pile **head, int value) {
    t_pile *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    t_pile *tmp = *head;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = new_node;
}

// Function to print the list
void print_list(t_pile *head) {
    t_pile *tmp = head;
    while (tmp != NULL) {
        // printf("Value: %d, Index: %d\n Pos : %d\n, target_pos : %d\n", tmp->value, tmp->idx, tmp->pos, tmp->target_pos);
		// printf("Pos : %d\n, target_pos : %d\n", tmp->pos, tmp->target_pos);
		// printf("Cost_a : %d Cost_b : %d\n", tmp->cost_a, tmp->cost_b);
		printf("Value %d", tmp->value);
        tmp = tmp->next;
    }
}




// Mock function to return the size of the list
int ft_pile_line(t_pile *a) {
    int size = 0;
    while (a != NULL) {
        size++;
        a = a->next;
    }
    return size;
}
int	is_sorted(t_pile *a)
{
	if ((!a || !a->next))
		return 1;
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}



int main() {
    t_pile *head = NULL;
	t_pile *new = NULL;

    // Creating a sample list
   
    append_node(&head, 1);
   
    append_node(&head, 35);
	 append_node(&head, 8);
   	basic_sort(&head);
	// append_node(&head, 105);
	//  append_node(&head, 100);
	//  append_node(&head, 521);
   	// append_node(&head, 9);
	// append_node(&head, 6);
   
	// append_node(&head, 41);
	// append_node(&head, 100);
	// append_node(&head, 3);
	// append_node(&head,33);
   

	

    // Call the set_index function
    // set_index(head);
	// push_in_b(&head, &new);
	// get_position(&head, &new);
	
	// get_target_pos(&head, &new);
	// push_cost(&head, &new);
    print_list(head);
	// printf("new\n");
	// print_list(new);
	

    // Free the list
    // t_pile *tmp1;
    // while (head != NULL) {
    //     tmp1 = head;
    //     head = head->next;
    //     free(tmp1);
    // }

    return 0;
}