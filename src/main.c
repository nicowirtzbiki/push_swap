/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 12:50:17 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/03/04 17:06:20 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a C program called push_swap that calculates 
**and displays the shortest sequence of Push_swap 
**instructions needed to sort the given integers.
**It accepts integers as command-line arguments and 
**outputs the sequence of operations needed to sort them.
*/
#include "push_swap.h"

/*
** Main function: parses input, sorts if needed, and cleans up.
**
** @param argc: Argument count
** @param argv: Argument values (integers to sort)
** @return: 0 on success
*/
int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	init_stack_a(&a, &argv[1]);
	if (stack_len(a) > 1 && !is_sorted(a))
		turk_sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
