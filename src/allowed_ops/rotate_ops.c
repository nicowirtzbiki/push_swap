/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:19:29 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:48 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotates stack up: first node becomes last.
** Does nothing if stack has fewer than 2 elements.
**
** @param stack: Pointer to the stack to rotate
*/
static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	first->next = NULL;
	first->prev = last;
	last->next = first;
}

/*
** Rotates stack 'a' up by 1.
**
** @param a: Pointer to stack a
** @param print: If 1, prints "ra" to stdout
*/
void	ra(t_stack **a, int print)
{
	rotate(a);
	if (print)
		ft_putstr_fd("ra\n", 1);
}

/*
** Rotates stack 'b' up by 1.
**
** @param b: Pointer to stack b
** @param print: If 1, prints "rb" to stdout
*/
void	rb(t_stack **b, int print)
{
	rotate(b);
	if (print)
		ft_putstr_fd("rb\n", 1);
}


/*
** Performs ra and rb simultaneously (rotates both stacks).
**
** @param a: Pointer to stack a
** @param b: Pointer to stack b
** @param print: If 1, prints "rr" to stdout
*/
void	rr(t_stack **a, t_stack **b, int print)
{
	rotate(a);
	rotate(b);
	if (print)
		ft_putstr_fd("rr\n", 1);
}
