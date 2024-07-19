/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:13:11 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/18 18:46:18 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_pile
{
	int				value;
	int				idx;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_pile	*next;
	struct s_pile	*prev;
}	t_pile;

typedef struct s_best
{
	int				cost_a;
	int 			cost_b;
}	t_best;

//pile_utils
t_pile			*get_last_node(t_pile *a);
int				ft_pile_size(t_pile *a);
t_pile			*set_node(int nbr);

//main
char			*ft_merge(char **av, int ac);
char			**ft_split(const char *s, char c);
void			fill_pile(t_pile **a, char **av, int ac);
int				is_sorted(t_pile *a);

//error
void			free_av(char **av);
void			exit_error(void);
void			free_pile(t_pile *a);
void			error_input(t_pile *a, char **av, int ac);

//parsing
static long		ft_atol(char *str, int *sign);
char			*ft_strjoin(char *s1, char *s2);

//pile_utils
t_pile			*get_last_node(t_pile *a);
void			add_to_pile(t_pile **a, int nbr);
int				is_number(char *s);
static int		is_repeated(t_pile *a, int nbr);
int				is_valid(t_pile *a, long nbr);

//split
static int		ft_count_arrays(const char *s, char c);
static size_t	ft_len(const char *s, char c);
static char		*ft_print_str(const char **str, char c);
static char		**ft_free_split(char **str, int a);

//operations
void			push(t_pile **a, t_pile **b);
void			pa(t_pile **a, t_pile **b);
void			pb(t_pile **a, t_pile **b);
void			rotate(t_pile **a);
void			ra(t_pile **a);
void			rb(t_pile **b);
void			rr(t_pile **a, t_pile **b);
void			rra(t_pile **a);
void			rrb(t_pile **b);
void			rrr(t_pile **a, t_pile **b);
void			swap(t_pile **a);
void			sa(t_pile **a);
void			sb(t_pile **b);

//push_swap utils
void			set_index(t_pile *a);
void			push_in_b(t_pile **a, t_pile **b);
void			sort(t_pile **a, t_pile **b);

//sort
int				get_target(t_pile **a, int idx_b, int target_pos);
void			get_target_pos(t_pile **a, t_pile **b);

void			get_position(t_pile **a, t_pile **b);
int				get_lowest_index_pos(t_pile **a);
void			basic_sort(t_pile **a);

//cost
void			push_cost(t_pile **a, t_pile **b);
void			best_move(t_pile **a, t_pile **b);
void			do_best_move(t_pile **a, t_pile **b, t_best *best);
int				n_abs(int nb);

//move
void			do_rotate(t_pile **a, t_pile **b, t_best *best);
void			do_rev_rotate(t_pile **a, t_pile **b, t_best *best);
void			do_rotate_a(t_pile **a, t_best *best);
void			do_rotate_b(t_pile **a, t_best *best);
void 			final_rotation(t_pile **a);

//basic_sort
void			basic_sort(t_pile **a);
static int		highest_value(t_pile *a);

// //test
// void	get_target_pos(t_pile **a, t_pile **b);
// static int	get_target(t_pile **a, int b_idx,
// 								int target_idx, int target_pos);
#endif