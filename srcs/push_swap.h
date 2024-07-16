/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:13:11 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/15 20:07:59 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
#include <unistd.h>

typedef struct s_pile
{
	int				value;
	int				idx;
	int				pos;
	int 			target_pos;
	// int				cost_a;
	// int 			cost_b;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

//pile_utils
t_pile	*get_last_node(t_pile *a);
int		ft_pile_size(t_pile *a);

//main
char	*ft_merge(char **av, int ac);
char	**ft_split(const char *s, char c);
void	fill_pile(t_pile **a, char **av, int ac);
int	is_sorted(t_pile *a);

//error
void	free_av(char **av);
void	exit_error(void);
void	free_pile(t_pile *a);
void	error_input(t_pile *a, char **av, int ac);


//parsing
static long ft_atol(char *str, int *sign);
char *ft_strjoin(char *s1, char *s2);


//pile_utils
t_pile	*get_last_node(t_pile *a);
void	add_to_pile(t_pile **a, int nbr);
int	is_number(char *s);
static int	is_repeated (t_pile *a, int nbr);
int	is_valid(t_pile *a, long nbr);

//split
static int	ft_count_arrays(const char *s, char c);
static size_t	ft_len(const char *s, char c);
static char	*ft_print_str(const char **str, char c);
static char	**ft_free_split(char **str, int a);

//operations
void	push(t_pile **a, t_pile **b);
void	pa(t_pile **a, t_pile **b);
void	pb(t_pile **a, t_pile **b);
void	rotate(t_pile **a);
void	ra(t_pile **a);
void	rb(t_pile **b);
void	rrotate(t_pile **a);
void	rra(t_pile **a);
void	rrb(t_pile **b);
void	rrr(t_pile **a, t_pile **b);
void	swap(t_pile **a);
void	sa(t_pile **a);
void	sb(t_pile **b);

//push_swap utils
void	set_index(t_pile *a);
void	push_in_b(t_pile **a, t_pile **b);

//sort_utils
// void	get_target_pos(t_pile **a, int idx_b, int  *target_pos);
void	get_target(t_pile **a, t_pile **b);
// void	get_lowest_index_pos(t_pile **a, int *lowest_pos);
void get_position(t_pile **a, t_pile **b);


//sort utils test a supprimer 
// void	get_position(t_pile **stack);
int	get_lowest_index_position(t_pile **stack);
static int	get_target(t_pile **a, int b_idx,int target_idx, int target_pos);
void	get_target_position(t_pile **a, t_pile **b);
#endif