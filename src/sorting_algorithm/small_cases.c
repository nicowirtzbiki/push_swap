/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_cases.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 20:30:10 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/16 21:17:37 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Sorts a stack with 2 or 3 elements using minimal operations.
** Returns immediately if already sorted or invalid stack.
**
** @param a: Pointer to stack A to sort
*/

void	sort_three(t_stack **a)
{
	int		len;
	t_stack	*max_node;

	if (!a || !*a || is_sorted(*a))
		return ;
	len = stack_len(*a);
	if (len == 2)
	{
		sa(a, 1);
		return ;
	}
	if (len != 3)
		return ;
	max_node = find_max(*a);
	if (max_node == *a)
		ra(a, 1);
	else if (max_node == (*a)->next)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}