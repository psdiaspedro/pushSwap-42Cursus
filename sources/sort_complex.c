/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:46 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/26 15:56:09 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	int	holder_top;
	int chunk;

	holder_top = stack_a->top + 1;
	chunk = 0;
	while((stack_a->top >= (holder_top / 2)) && !is_sorted(stack_a))
	{
		while (stack_a->stack[stack_a->top] < mid && !is_sorted(stack_a)
				&& stack_a->top > 1)
		{
			push(stack_a, stack_b);
			chunk++;
		}
		i = 0;
		while(stack_a->stack[i] < mid && !is_sorted(stack_a)
				&& stack_a->top > 1)
		{
			reverse_rotate(stack_a);
			push(stack_a, stack_b);
			chunk++;
			i++;
		}
		while ((stack_a->top >= (holder_top / 2)) && !is_sorted(stack_a))
		{
			if (stack_a->stack[stack_a->top] < mid)
			{
				push(stack_a, stack_b);
				chunk++;
			}
			else
				rotate(stack_a);
		}
	}
	return (chunk);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*copy;
	int	mid;
	t_stack *chunks;

	chunks = create_stack(capacity_chunk(stack_a->capacity), 'c');
	while (stack_a->top > 1)
	{
		copy = init_copy(stack_a->stack, stack_a->top + 1);
		mid = insertion_sort(copy, stack_a->top + 1);
		//free(copy);
		chunks->top++;
		chunks->stack[chunks->top] = get_chunk(stack_a, stack_b, mid);
	}
	// free(chunks->stack);
	// free(chunks);
}
 // 0 1 3 5 6 7 9 10 11 12
