/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 22:37:51 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:32 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns the maximum of two integers.
**
** @param a: First integer
** @param b: Second integer
** @return: Larger of a and b
*/
static int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

/*
** Calculates push_cost for each node in A when moving to B.
** Considers rotation costs and opportunities for combined rotations.
**
** @param a: Stack A (source)
** @param b: Stack B (destination)
*/
void	set_cost_a(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!a->above_median)
			a->push_cost = len_a - a->index;
		if (a->target_node && a->above_median
			&& a->target_node->above_median)
			a->push_cost = max_int(a->index, a->target_node->index);
		else if (a->target_node && !a->above_median
			&& !a->target_node->above_median)
			a->push_cost = max_int(len_a - a->index,
					len_b - a->target_node->index);
		else if (a->target_node && a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else if (a->target_node)
			a->push_cost += len_b - a->target_node->index;
		a = a->next;
	}
}

/*
** Marks the node with the lowest push_cost as cheapest.
** Clears cheapest flag on all other nodes.
**
** @param stack: Stack to analyze
*/
void	set_cheapest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*best;
	long	min_cost;

	tmp = stack;
	best = NULL;
	min_cost = LONG_MAX;
	while (tmp)
	{
		tmp->cheapest = false;
		if (tmp->push_cost < min_cost)
		{
			min_cost = tmp->push_cost;
			best = tmp;
		}
		tmp = tmp->next;
	}
	if (best)
		best->cheapest = true;
}