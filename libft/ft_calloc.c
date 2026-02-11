/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nico <nico@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 09:52:00 by nico              #+#    #+#             */
/*   Updated: 2026/02/11 10:02:39 by nico             ###   ########.fr       */
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

