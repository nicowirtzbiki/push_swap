/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 19:29:18 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:57:11 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_bzero(void *s, size_t n)
{
    size_t  i;
    unsigned char   *ptr;

    if (!s)
        return ;
    i = 0;
    ptr = (unsigned char *)s;
    while (i < n)
    {
        ptr[i] = 0;
        i++;
    }
}