/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paugusto <paugusto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:43 by pedroadias        #+#    #+#             */
/*   Updated: 2021/11/01 19:39:21 by paugusto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	short_sort(t_stack *stack)
{
	if (!is_sorted(stack))
	{
		if ((stack->stack[0] > stack->stack[1])
			&& (stack->stack[0] > stack->stack[2]))
			swap(stack);
		else if ((stack->stack[0] < stack->stack[1])
			&& (stack->stack[0] < stack->stack[2])
			&& (stack->stack[2] > stack->stack[1]))
		{
			rotate(stack);
			swap(stack);
		}
		else if ((stack->stack[0] < stack->stack[1])
			&& (stack->stack[0] < stack->stack[2]))
			reverse_rotate(stack);
		else if ((stack->stack[0] > stack->stack[1])
			&& (stack->stack[0] < stack->stack[2]))
			rotate(stack);
		else
		{
			swap(stack);
			rotate(stack);
		}
	}
}

void	small_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	small;

	while (stack_a->top > 2)
	{
		small = find_smaller(stack_a);
		if (stack_a->stack[stack_a->top - 1] == small)
			swap(stack_a);
		else if (stack_a->stack[stack_a->top - 2] == small)
		{
			rotate(stack_a);
			rotate(stack_a);
		}
		else if (stack_a->stack[1] == small)
		{
			reverse_rotate(stack_a);
			reverse_rotate(stack_a);
		}
		else if (stack_a->stack[0] == small)
			reverse_rotate(stack_a);
		push(stack_a, stack_b);
	}
	short_sort(stack_a);
	push(stack_b, stack_a);
	if (stack_a->capacity == 5)
		push(stack_b, stack_a);
}

void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->capacity == 3)
		short_sort(stack_a);
	else if (stack_a->capacity <= 5)
		small_sort(stack_a, stack_b);
}
