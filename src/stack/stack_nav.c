/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:33:07 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/14 11:35:31 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Counts and returns the number of elements in the stack.
**
** @param stack: Stack to measure
** @return: Number of nodes in the stack
*/
int	stack_len(t_stack *stack)
{
	int		i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}
/*
** Finds and returns the last node in the stack.
**
** @param stack: Stack to search
** @return: Pointer to last node, or NULL if stack is empty
*/
t_stack	*find_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}