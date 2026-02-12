/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 12:50:17 by nico              #+#    #+#             */
/*   Updated: 2026/02/12 21:28:36 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Write a C program called push_swap that calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.
It accepts integers as command-line arguments and outputs the sequence of operations needed to sort them.*/

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a; //crio stack 1 e stack 2
    t_stack *b;

    a = NULL;
    b = NULL; //inicializo as stacks como NULL
    if (argc < 2) //se nao tiver argumentos, finalize
        return (0);
    init_stack_a(&a, &argv[1]);
    if (stack_len(a) > 1 && !is_sorted(a)) //se tivermos mais de 1 elemento na stack e nao estiverem ordenados, chama o turk_sort
        turk_sort(&a, &b);
    free_stack(&a); //enderećo do ponteiro, ou seja, &a == t_stack **
    free_stack(&b);
    return (0);
}