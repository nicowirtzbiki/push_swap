/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 21:56:20 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:14 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotates stack A until the minimum value is at the top.
** Chooses the shorter rotation path (ra or rra).
**
** @param a: Pointer to stack A
*/
void	min_on_top(t_stack **a)
{
	int		len;
	int		moves;
	t_stack	*min;

	if (!a || !*a)
		return ;
	set_current_position(*a);
	len = stack_len(*a);
	min = find_min(*a);
	if (!min)
		return ;
	moves = min->index;
	if (moves <= len / 2)
		while (moves--)
			ra(a, 1);
	else
	{
		moves = len - moves;
		while (moves--)
			rra(a, 1);
	}
}