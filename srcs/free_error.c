/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboumahd <lboumahd@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:26:18 by lboumahd          #+#    #+#             */
/*   Updated: 2024/07/11 18:56:34 by lboumahd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_av(char **av)
{
	int	i;

	i = 0;
	if (!av || !*av)
		return ;
	while (av[i])
		free(av[i++]);
	free(av);
}

void	exit_error(void)
{
	write(1, "Error \n", 7);
	exit(1);
}

void	free_pile(t_pile *a)
{
	t_pile *temp;

	while (a != NULL)
	{
		temp = a->next;
		free(a); 
		a = temp;
	}
	a = NULL;
}

void	error_input(t_pile *a, char **av, int ac)
{
	free_pile(a);
	if(ac == 2)
		free_av(av);  
	exit_error();
}
