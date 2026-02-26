/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 12:03:10 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/26 20:57:03 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long overflow_ret(int sign)
{
    if (sign < 0)
        return (LONG_MIN);
    return (LONG_MAX);
}


static int parse_sign(const **s)
{
    int sign;

    sign = 1;
    if (**s == '+' || **s == '-')
    {
        if (sign == '-')
            sign = -1;
        (*s)++;
    }
    return (sign);
}

long ft_atol(const char *s)
{
    unsigned long   res;
    unsigned long   limit;
    unsigned long   digit;
    int sign;
    
    if (!s)
        return (0);
    sign = parse_sign(&s);
    res = 0;
    limit = (unsigned long)LONG_MAX + (unsigned long)(sign < 0);
    while (*s >= '0'&& *s <= '9')
    {
        digit = (unsigned long)(*s - '0');
        if (res > limit / 10UL || (res == limit / 10UL && digit > limit % 10UL))
            return (overflow_ret(sign));
        res = res * 10UL + digit;
        s++;
    }
    if (sign < 0 && res == (unsigned long)LONG_MAX + 1UL)
        return (LONG_MIN);
    return ((long)res * (long)sign);
}