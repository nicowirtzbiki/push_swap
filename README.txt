*This project has been created as part of the 42 curriculum by nwirtzbi.*

# **Project Title**

push_swap

---

## *Description*
(clearly presents the project, including its goal and a
brief overview)

The program push_swap calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.

O push_swap tem 4 grandes responsabilidades:
- Ler e validar a entrada
- Representar as stacks em memória
- Executa
r comandos permitidos
- Decidir quais comandos usar para ordenar

## *Instructions*
(any relevant information about compilation,
installation, and/or execution)

Usage: ./push_swap [numbers...]
Example: ./push_swap 3 2 1 0 -> outputs operations to sort

Allowed operations:
- sa/sb/ss: swap first two elements
- pa/pb: push from one stack to another
- ra/rb/rr: rotate up (first becomes last)
- rra/rrb/rrr: reverse rotate down (last becomes first)

The program uses the Turk algorithm for efficient sorting.

Main function: parses input, sorts if needed, and cleans up.
@param argc: Argument count
@param argv: Argument values (integers to sort)
@return: 0 on success


- Files to submit: Makefile, *.h, *.c
- Project files structure:

push_swap/ 
 
├── libft/ 
    ├──Makefile 
    ├──ft_atol.c 
    ├──ft_bzero.c 
    ├──ft_calloc.c 
    ├──ft_isdigit.c 
    ├──ft_putstr_fd.c 
    ├──ft_split.c 
    ├──ft_strdup.c 
    ├──ft_strlen.c 
    ├──ft_strncmp.c 
    ├──ft_substr.c 
    ├──libft.h 
├── src/ 
    ├──sorting_algorithm/ 
        ├──calc_costs.c 
        ├── execute_moves.c 
        ├──final_rotation.c 
        ├──find_targets.c 
        ├──init_nodes.c 
        ├──rotation_moves.c 
        ├──small_cases.c 
        ├──turk_sort.c 
    ├──allowed_ops/ 
        ├──push_ops.c 
        ├──rev_rotate_ops.c 
        ├──rotate_ops.c 
        ├──swap_ops.c 
    ├──parsing/ 
        ├──input_to_stack.c 
        ├──parse_validate.c 
    ├──stack/ 
        ├──stack_nav.c 
        ├──stack_ops.c 
        ├──stack_order.c 
    ├──main.c
├── .gitignore ok
├── Makefile 
├──push_swap.h 
└── README.md

## *Resources*
(section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.)

* Debian Documentation
* man pages (`man sshd`, `man apt`, `man ufw`, `man apparmor`)
* 42 subject PDF
* Basic Linux administration tutorials

## AI Usage

AI (ChatGPT) was used to:

* Format and simplify this README
* Help create clear explanations
* Organize sections
* Explain concepts
