/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 21:52:07 by nico              #+#    #+#             */
/*   Updated: 2026/02/12 21:28:17 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Handles errors by freeing resources, printing "Error" and exiting.
**
** @param a: Stack to free
** @param split: String array to free (if any)
*/

static void error_exit(t_stack **a, char **split)
{
    if (split)
        free_split(split);
    free_stack(a);
    write(2, "Error\n", 6);
    exit(1);
}

static void	parse_and_add(t_stack **a, const char *token, char **split_ctx)
{
	long	n;

	if (!is_valid_int_token(token))
		error_exit(a, split_ctx);
	n = ft_atol(token);
	if (n > INT_MAX || n < INT_MIN)
		error_exit(a, split_ctx);
	if (check_duplicate(*a, (int)n))
		error_exit(a, split_ctx);
	append_node(a, (int)n);
}

void    init_stack_a(t_stack **a, char **argv)
{
    
}