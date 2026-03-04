# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nwirtzbi <nwirtzbi@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/04 17:03:19 by nwirtzbi          #+#    #+#              #
#    Updated: 2026/03/04 17:03:19 by nwirtzbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

*This project has been created as part of the 42 curriculum by nwirtzbi.*

# **Project Title**

push_swap

---

## *Description*
push_swap is a sorting algorithm project from the 42 curriculum.

The goal is to sort a list of integers using:

- Two stacks (A and B)
- A restricted set of allowed operations

The program must output the smallest possible sequence of operations that sorts stack A in ascending order while keeping stack B empty.

This implementation uses a *cost-based greedy strategy (Turk Algorithm)* to determine the most efficient move at each step.

The program push_swap calculates and displays the shortest sequence of Push_swap instructions needed to sort the given integers.

---

## *Instructions*

### The push_swap program has four main responsibilities:

- Reading and validating input
- Representing stacks in memory
- Executing allowed commands
- Deciding which commands to use for sorting

### Allowed operations:
- sa/sb/ss: swap first two elements
- pa/pb: push top node from one stack to another
- ra/rb/rr: rotate up (first becomes last)
- rra/rrb/rrr: reverse rotate down (last becomes first)
Each operation runs in *O(1)* time.

### Compilation:
- make // compilation
- make clean //clean object files
- make fclean //full clean (objects + binary)
- make re //rebuild

### Execution
- **Multiple arguments**
./push_swap 4 67 3 87 23

- **Single string argument
./push_swap "4 67 3 87 23"

- **Count the number of operations**
./push_swap 4 67 3 87 23 | wc -l

- **Generate 100 randomnumbers and test**
ARG=$(shuf -i 1-500 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

- **Generate 500 randomnumbers and test**
ARG=$(shuf -i 1-50000 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l

- **Test for leaks**
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1
valgrind --leak-check=full --show-leak-kinds=all ./push_swap $(shuf -i 1-100 -n 100)


### Usage: ./push_swap [numbers...]
- Example 1 : ./push_swap 3 -2 1 0 -> outputs operations to sort
- Example 2 : ./push_swap "6 8" "3 1 2 0" -> outputs operations to sort
The program prints the required operations to stdout, one per line.

### Error Handling
The program prints *Error* to stderr and exits with status 1 if:

- Invalid integer format
- Duplicate values
- Integer overflow
- Memory allocation failure
Otherwise, it exits with status 0.

### Project Structure
- Files to submit: Makefile, *.h, *.c
- Project files structure:

push_swap/

    ├── libft/ 
        ├──Makefile 
        ├──ft_atol.c //used in input_to_stack.c e parse_validate.c
        ├──ft_isdigit.c //used in parse_validade.c
        ├──ft_putstr_fd.c //used in allowed_ops
        ├──ft_split.c //used in input_to_stack.c
        ├──ft_strlen.c //used in ft_substr.c
        ├──ft_substr.c //used in ft_split.c
        ├──libft.h 
    ├── src/
        ├──sorting_algorithm/ 
            ├──calc_costs.c 
            ├── execute_moves.c 
            ├──final_rotation.c 
            ├──find_targets.c 
            ├──init_nodes.c 
            ├──a2b_rotation_moves.c 
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
        ├──push_swap.h 
    ├── Makefile 
    └── README.md


- **Main function:** parses input, sorts if needed, and cleans up.
    - @param argc: Argument count
    - @param argv: Argument values (integers to sort)
    - @return: 0 on success

### Algorithm
This project uses a Turk-based greedy algorithm:

- Push most elements from A to B
- For each element, calculate:
- Cost to move it to the top
- Cost to reach its correct target
- Select the cheapest move
- Execute combined rotations when possible
- Repeat until sorted
- Perform a final rotation to position the smallest element on top

This approach ensures efficient performance within 42 evaluation limits.
Expected operation counts:

- 3 numbers → ≤ 3 operations
- 5 numbers → ≤ 12 operations
- 100 numbers → < 700 operations
- 500 numbers → < 5500 operations

---

## *Resources*
(section listing classic references related to the topic (documentation, articles, tutorials, etc.), as well as a description of how AI was used — specifying for which tasks and which parts of the project.)

* Debian Documentation
* man pages (`man sshd`, `man apt`, `man ufw`, `man apparmor`)
* 42 subject PDF
* Basic Linux administration tutorials

---

## AI Usage

AI (ChatGPT) was used to:

* Format and simplify this README
* Help create clear explanations
* Organize sections
* Explain concepts
