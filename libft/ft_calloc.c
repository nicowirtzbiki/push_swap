/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:52:00 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:57:20 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_calloc(size_t count, size_t size)
{
    size_t  total;
    void    *mem;

    total = count * size;
    mem = malloc(total);
    if (!mem)
        return (NULL);
    ft_bzero(mem, total);
    return (mem);
}

