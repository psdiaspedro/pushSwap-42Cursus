/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:46 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 14:44:18 by pedroadias       ###   ########.fr       */
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

	copy = init_copy(stack->stack, 0, stack->top);
	mid = insertion_sort(copy, stack->top + 1);
	free(copy);
	return (mid);
}

int	get_mid_chunk(t_stack *stack, t_stack *chunks)
{
	int	mid;
	int	*copy;
	int	i;
	int	j;

	copy = malloc(sizeof(int) * chunks->stack[chunks->top]);
	i = stack->top + 1 - chunks->stack[chunks->top];
	j = 0;
	while (i <= stack->top)
	{
		copy[j] = stack->stack[i];
		i++;
		j++;
	}
	mid = insertion_sort(copy, chunks->stack[chunks->top]);
	free(copy);
	return (mid);
}

void	sorting_last_items(t_stack *stack_a, t_stack *stack_b, t_stack *chunks)
{
	if (!is_sorted(stack_a))
		swap(stack_a);
	if (chunks->stack[chunks->top] == 1)
	{
		push(stack_b, stack_a);
		chunks->stack[chunks->top] = 0;
		chunks->top--;
	}
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	t_stack	*chunks;

	chunks = create_stack(capacity_chunk(stack_a->capacity), 'c');
	while (stack_a->top > 1 && !is_sorted(stack_a))
	{
		mid = get_mid(stack_a);
		chunks->top++;
		chunks->stack[chunks->top] = get_chunk(stack_a, stack_b, mid);
	}
	sorting_last_items(stack_a, stack_b, chunks);
	while (stack_a->top < stack_a->capacity - 1)
	{
		if (is_b_sorted(stack_b))
			while (stack_a->top < stack_a->capacity - 1)
				push(stack_b, stack_a);
		// mid = get_mid_chunk(stack_b, chunks);
	}
	free(chunks->stack);
	free(chunks);
}

