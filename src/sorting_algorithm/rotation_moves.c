/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 18:50:34 by nico              #+#    #+#             */
/*   Updated: 2026/02/25 23:06:29 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Performs individual rotations on stacks A and B.
** Used when combined rotations (rr/rrr) are not applicable.
**
** @param a: Pointer to stack A
** @param b: Pointer to stack B
** @param node: Node being moved with target information
*/
void	do_single_rotations(t_stack **a, t_stack **b, t_stack *node)
{
	if (*a != node)
	{
		if (node->above_median)
			ra(a, 1);
		else
			rra(a, 1);
	}
	if (node->target_node && *b != node->target_node)
	{
		if (node->target_node->above_median)
			rb(b, 1);
		else
			rrb(b, 1);
	}
}

/*
** Executes one rotation step, optimizing with rr/rrr when possible.
** Chooses combined rotation if both stacks rotate in same direction.
**
** @param a: Pointer to stack A
** @param b: Pointer to stack B
** @param node: Node being moved with target information
*/
void	do_rotation_step(t_stack **a, t_stack **b, t_stack *node)
{
    
}

/*
** Rotates stacks until node is at top of A and target is at top of B.
** Updates positions dynamically during rotation.
**
** @param a: Pointer to stack A
** @param b: Pointer to stack B
** @param node: Node to bring to top with its target
*/
void	bring_nodes_to_top(t_stack **a, t_stack **b, t_stack *node)
{

}