/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 22:26:44 by nico              #+#    #+#             */
/*   Updated: 2026/02/25 23:14:40 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


/*
** Move Execution
**
** Public interface for executing the cheapest moves between stacks.
** This module orchestrates the physical movement of elements:
**
** move_a_to_b:
**   1. Identifies the cheapest node in A
**   2. Rotates both stacks to bring node and target to top
**   3. Executes pb to push from A to B
**
** move_b_to_a:
**   1. Takes the top element from B
**   2. Rotates A to align target position
**   3. Executes pa to push from B to A
**
** Rotation optimization is handled by rotation_moves.c helpers.
*/

/*
** Finds and returns the node marked as cheapest in stack A.
**
** @param a: Stack A to search
** @return: Node with cheapest flag set, or NULL
*/
static t_stack	*find_cheapest_node(t_stack *a)
{
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

/*
** Moves the cheapest node from A to B.
** Rotates both stacks optimally, then executes pb.
**
** @param a: Pointer to stack A (source)
** @param b: Pointer to stack B (destination)
*/
void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (!a || !*a)
		return ;
	node = find_cheapest_node(*a);
	if (!node)
		return ;
	bring_nodes_to_top(a, b, node);
	pb(a, b, 1);
}

/*
** Moves the top element from B to A at its target position.
** Rotates A to align target, then executes pa.
**
** @param a: Pointer to stack A (destination)
** @param b: Pointer to stack B (source)
*/
void	move_b_to_a(t_stack **a, t_stack **b)
{
    t_stack *node;

    if (!a || !b || !*b)
        return ;
    node = *b;
    
}