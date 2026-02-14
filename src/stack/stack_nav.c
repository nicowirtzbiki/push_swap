/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_nav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 13:33:07 by nico              #+#    #+#             */
/*   Updated: 2026/02/13 13:36:13 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// Provides basic navigation and measurement functions for stack structures.

int stack_len(t_stack *stack)
{
    int i;

    i = 0;
    while(stack)
    {
        i++;
        stack = stack->next;
    }
    return (i);
}