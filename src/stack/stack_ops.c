/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 10:15:26 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/14 12:13:16 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Creates a new node with value n and appends it to the end of the stack.
** Initializes all node fields to default values.
**
** @param stack: Pointer to stack pointer
** @param n: Integer value to store in the new node
*/
void	append_node(t_stack **stack, int n)
{
	t_stack	*new;
	t_stack	*last;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = n;
	new->index = 0;
	new->push_cost = 0;
	new->above_median = false;
	new->cheapest = false;
	new->target_node = NULL;
	new->next = NULL;
	new->prev = NULL;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = find_last(*stack);
	last->next = new;
	new->prev = last;
}

/*
** Frees all nodes in the stack and sets the stack pointer to NULL.
** Prevents memory leaks by deallocating every node.
**
** @param stack: Pointer to stack pointer to free
*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}