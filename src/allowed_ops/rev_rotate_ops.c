/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 19:18:21 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:56:46 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Rotates stack down: last element becomes first.
** Does nothing if stack has fewer than 2 elements.
**
** @param stack: Pointer to the stack to reverse rotate
*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}

/*
** Reverse rotates stack 'a' down by 1.
**
** @param a: Pointer to stack a
** @param print: If 1, prints "rra" to stdout
*/
void	rra(t_stack **a, int print)
{
	rev_rotate(a);
	if (print)
		ft_putstr_fd("rra\n", 1);
}

/*
** Reverse rotates stack 'b' down by 1.
**
** @param b: Pointer to stack b
** @param print: If 1, prints "rrb" to stdout
*/
void	rrb(t_stack **b, int print)
{
	rev_rotate(b);
	if (print)
		ft_putstr_fd("rrb\n", 1);
}

/*
** Performs rra and rrb simultaneously (reverse rotates both stacks).
**
** @param a: Pointer to stack a
** @param b: Pointer to stack b
** @param print: If 1, prints "rrr" to stdout
*/
void	rrr(t_stack **a, t_stack **b, int print)
{
	rev_rotate(a);
	rev_rotate(b);
	if (print)
		ft_putstr_fd("rrr\n", 1);
}