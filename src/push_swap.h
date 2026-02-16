/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 11:59:10 by nwirtzbi          #+#    #+#             */
/*   Updated: 2026/02/16 21:19:22 by nwirtzbi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
    int             value;
    int             index; // indice que representa a posicao ordenada do valor
    int             push_cost; //qts operacoes sao necessarias para mover este no para a posicao correta. usado para escolher o movimento mais barato.
    bool            above_median; //se o nó está localizado na metade superior da stack
    bool            cheapest; //se o nó é o mais barato
    struct s_stack  *next; 
    struct s_stack  *prev; 
    struct s_stack  *target_node; // ponteiro para o no onde este deve ser inserido
    
}   t_stack;

// allowed_ops
void    sa(t_stack **a, int print);
void    sb(t_stack **b, int print);
void    ss(t_stack **a, t_stack **b, int print);

void    pa(t_stack **a, t_stack **b, int print);
void    pb(t_stack **b, t_stack **a, int print);

void    ra(t_stack **a, int print);
void    rb(t_stack **b, int print);
void    rr(t_stack **a, t_stack **b, int print);

void    rra(t_stack **a, int print);
void    rrb(t_stack **b, int print);
void    rrr(t_stack **a, t_stack **b, int print);

// Turk algorithm helpers
void	turk_sort(t_stack **a, t_stack **b);
void	init_nodes_a(t_stack *a, t_stack *b);
void	init_nodes_b(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);
void	move_b_to_a(t_stack **a, t_stack **b);
void	bring_nodes_to_top(t_stack **a, t_stack **b, t_stack *node);
void	do_rotation_step(t_stack **a, t_stack **b, t_stack *node);
void	do_single_rotations(t_stack **a, t_stack **b, t_stack *node);
t_stack	*get_cheapest(t_stack *stack);

// Turk algorithm - cost/target calculation
void	set_current_position(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_cost_a(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *stack);
void	set_target_b(t_stack *b, t_stack *a);

// Small sorts and final rotation
void	sort_three(t_stack **a);
void	min_on_top(t_stack **a);

// Parsing (validade, split_free, input_to_stack)
bool	is_valid_int_token(const char *s);
bool	check_duplicate(t_stack *stack, int value);
void	free_split(char **arr);

// Stack initialization
void	init_stack_a(t_stack **a, char **argv);

// Stack utils (nav, order and ops)

int		stack_len(t_stack *stack);
t_stack	*find_last(t_stack *stack);

bool	is_sorted(t_stack *stack);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);

void	append_node(t_stack **stack, int n);
void	free_stack(t_stack **stack);

#endif