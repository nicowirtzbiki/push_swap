/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 19:28:03 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/23 22:32:16 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Updates index and above_median fields for all nodes in the stack.
** Index is 0-based position, above_median indicates if in upper half.
**
** @param stack: Stack to update positions for
*/
void	set_current_position(t_stack *stack)
{
	int	i;
	int	median;

	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

/*
** Initializes all node metadata when moving from A to B.
** Sets positions, targets, costs, and marks cheapest node.
**
** @param a: Stack A (source)
** @param b: Stack B (destination)
*/
void	init_nodes_a(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_a(a, b);
	set_cost_a(a, b);
	set_cheapest(a);
}

/*
** Initializes node metadata when moving from B to A.
** Sets positions and targets for proper insertion.
**
** @param a: Stack A (destination)
** @param b: Stack B (source)
*/
void	init_nodes_b(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_b(b, a);
}