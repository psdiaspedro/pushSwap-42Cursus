/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:46 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 11:09:02 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int		capacity_chunk(int capacity)
{
	int	i;

	i = 0;
	while(capacity >= 2)
	{
		capacity /= 2;
		i++;
	}
	return (i);
}

int	is_mid_smaller(t_stack *stack, int mid)
{
	int	i;
	i = 0;
	while (i <= stack->top)
	{
		if (stack->stack[i] >= mid)
			i++;
		else
			return (0);
	}
	return (1);
}

int	get_chunk(t_stack *stack_a, t_stack *stack_b, int mid)
{
	int	i;
	int	chunk;

	chunk = 0;
	while (stack_a->stack[stack_a->top] < mid && !is_sorted(stack_a))
	{
		push(stack_a, stack_b);
		chunk++;
	}
	i = 0;
	while (stack_a->stack[i] < mid && !is_sorted(stack_a) && stack_a->top > 1)
	{
		reverse_rotate(stack_a);
		push(stack_a, stack_b);
		i++;
		chunk++;
	}
	while (!is_mid_smaller(stack_a, mid) )
	{
		while (stack_a->stack[stack_a->top] >= mid && !is_sorted(stack_a))
			rotate(stack_a);
		push(stack_a, stack_b);
		chunk++;
	}
	return (chunk);
}

int	get_mid(t_stack *stack)
{
	int	*copy;
	int	mid;

	copy = init_copy(stack->stack, stack->top + 1);
	mid = insertion_sort(copy, stack->top + 1);
	free(copy);
	return (mid);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	t_stack *chunks;

	chunks = create_stack(capacity_chunk(stack_a->capacity), 'c');
	while (stack_a->top > 1 && !is_sorted(stack_a))
	{
		mid = get_mid(stack_a);
		chunks->top++;
		chunks->stack[chunks->top] = get_chunk(stack_a, stack_b, mid);
	}
	free(chunks->stack);
	free(chunks);
}
//0 1 3 4 5 6 7 9 10 11 12 15
