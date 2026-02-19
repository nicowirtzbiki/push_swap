/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 20:06:13 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/19 21:18:26 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
** Finds the largest value in B that is still smaller than the element.
** If no such value exists, uses the maximum value in B.
** This ensures elements are inserted in descending order in B.
** Returns the largest value smaller than val, or max if none exists.
**
** @param b: Stack B to search
** @param val: Value to find target for
** @return: Target node in B
*/
static t_stack	*find_target_in_b(t_stack *b, int val)
{
	t_stack	*best;
	t_stack	*it;

	if (!b)
		return (NULL);
	best = NULL;
	it = b;
	while (it)
	{
		if (it->value < val)
			if (!best || it->value > best->value)
				best = it;
		it = it->next;
	}
	if (best)
		return (best);
	return (find_max(b));
}

/*
** Sets target_node for each element in A, pointing to its insertion point in B.
**
** @param a: Stack A (source)
** @param b: Stack B (destination)
*/
void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp)
	{
		tmp->target_node = find_target_in_b(b, tmp->value);
		tmp = tmp->next;
	}
}


