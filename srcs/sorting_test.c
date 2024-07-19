#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
// Define the t_pile structure


// Function prototypes
t_pile *new_node(int value);
void append_node(t_pile **head, int value);
void print_list(t_pile *head);


int main() {
    t_pile *a = NULL;
	t_pile *b = NULL;

    // Create a test list: 2 -> 3 -> 1
    append_node(&a, 2);
    append_node(&a, 10);
    append_node(&a, 48);
	append_node(&b, 54);
	append_node(&b, 87);
	append_node(&b, 8);
	append_node(&b, 5);
	append_node(&b, 1);
	append_node(&b, 3);
	append_node(&b, 12);
	append_node(&b, 125);

    printf("Original list:\n");
    print_list(a);

    basic_sort(&a);
	set_index(a);
	set_index(b);
	get_position(&a, &b);
	get_target_pos(&a, &b);
	push_cost(&a, &b);
	// best_move(&a, &b);

    printf("b\n");

	print_list(b);

    return 0;
}

t_pile *new_node(int value) {
    t_pile *new = (t_pile *)malloc(sizeof(t_pile));
    if (!new) return NULL;
    new->value = value;
	new->cost_a = -1;
	new->cost_b = -1;
	new->target_pos = -1;
	new->pos = 0;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

// Append a node to the list
void append_node(t_pile **head, int value) {
    t_pile *new = new_node(value);
    if (!new) return;
    if (!*head) {
        *head = new;
        return;
    }
    t_pile *tmp = *head;
    while (tmp->next) {
        tmp = tmp->next;
    }
    tmp->next = new;
    new->prev = tmp;
}

// Print the list
void print_list(t_pile *head) {
    t_pile *tmp = head;
    while (tmp) {
        printf("value : %d ", tmp->value);
		printf("cost_b : %d ", tmp->cost_b);
		printf("cost_a : %d \n", tmp->cost_a);
        tmp = tmp->next;
    }
    printf("\n");
}





