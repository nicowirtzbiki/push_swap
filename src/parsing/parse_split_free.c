/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_split_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:40:01 by nico              #+#    #+#             */
/*   Updated: 2026/02/11 21:19:55 by nico             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** String Array Memory Management
**
** Provides deallocation utilities for string arrays created by split_ws.
** Handles both successful splits and cleanup on allocation failures.
*/

/*
** Frees the first j elements of an array and the array itself.
** Used for cleanup when allocation fails mid-process.
**
** @param arr: Array to free
** @param j: Number of elements to free before freeing array
*/

void	free_arr_on_error(char **arr, int j)
{
	int	k;

	k = 0;
	while (k < j)
	{
		free(arr[k]);
		k++;
	}
	free(arr);
}

/*
** Frees all strings in a null-terminated array and the array itself.
**
** @param arr: Null-terminated string array to free
*/

void    free_split(char **arr)
{
    int k;

    if (!arr)
        return;
    k = 0;
    while (arr[k])
    {
        free(arr[k]);
        k++;
    }
    free(arr);
}
