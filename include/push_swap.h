/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:44:05 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 16:02:40 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int		capacity;
	int		top;
	int		*stack;
	char	c;
}	t_stack;

void	init_stack(t_stack *stack , char **argv);
t_stack	*create_stack(int capacity, char c);
int		validate(char **argv);
void	swap(t_stack *stack);
void	push(t_stack *stack_src, t_stack *stack_dst);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	double_swap(t_stack *stack_a, t_stack *stack_b);
void	double_rotate(t_stack *stack_a, t_stack *stack_b);
void	double_reverse_rotate(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack);
void	simple_sort(t_stack *stack);
void	complex_sort(t_stack *stack_a, t_stack *stack_b);
int		insertion_sort(int array[], int len);
int		*init_copy(int *array, int start, int end);
int		is_mid_smaller(t_stack *stack, int mid);
int		is_b_sorted(t_stack *stack);
int		capacity_chunk(int capacity);
int		get_mid(t_stack *stack);
int		get_mid_chunk(t_stack *stack, t_stack *chunks);
int		is_chunk_sorted(t_stack *stack, int len);
int		is_mid_higher(t_stack *stack, t_stack *chunks, int mid);

#endif
