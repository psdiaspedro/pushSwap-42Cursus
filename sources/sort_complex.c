/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:46 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/28 16:45:23 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	recalc_chunk(t_stack *stack_a, t_stack *stack_b, t_stack *chunks, int mid, int len)
{
	int	rotate_counter;

	rotate_counter = 0;
	while (stack_a->stack[stack_a->top] >= mid && !is_mid_smaller_chunk(stack_a,mid, len))
	{
		rotate(stack_b);
		rotate_counter++;
	}
	push(stack_a, stack_b);
	chunks->stack[chunks->top]++;
	while(rotate_counter > 0)
	{
		reverse_rotate(stack_a);
		rotate_counter--;
	}
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
	while (!is_mid_smaller(stack_a, mid))
	{
		while (stack_a->stack[stack_a->top] >= mid && !is_sorted(stack_a))
			rotate(stack_a);
		push(stack_a, stack_b);
		chunk++;
	}
	return (chunk);
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

void	move_higher(t_stack *stack_a, t_stack *stack_b, t_stack *chunks, int mid)
{
	int	rotate_counter;

	rotate_counter = 0;
	while (stack_b->stack[stack_b->top] <= mid && !is_mid_higher(stack_b, chunks, mid))
	{
		rotate(stack_b);
		rotate_counter++;
	}
	push(stack_b, stack_a);
	chunks->stack[chunks->top]--;
	if(chunks->top > 0)
	{
		while(rotate_counter > 0)
		{
			reverse_rotate(stack_b);
			rotate_counter--;
		}
	}
}

void	move_chunk(t_stack *stack_a, t_stack *stack_b, t_stack *chunks)
{
 	int	mid;
	int	pushs_to_a;

 	while (chunks->stack[chunks->top] > 0)
 	{
		if (chunks->stack[chunks->top] <= 2)
		{
			if (is_chunk_sorted(stack_b, chunks->stack[chunks->top]))
			{
				push(stack_b, stack_a);
				chunks->stack[chunks->top]--;
			}
			else
				swap(stack_b);
		}
		else
		{
			mid = get_mid_chunk(stack_b, chunks);
			printf("mid: %d\n", mid);
			pushs_to_a = 0;
			while (!is_mid_higher(stack_b, chunks, mid))
			{
				if (is_chunk_sorted(stack_b, chunks->stack[chunks->top]))
				{
					push(stack_b, stack_a);
					chunks->stack[chunks->top]--;
				}
				else
				{
					move_higher(stack_a, stack_b, chunks, mid);
					pushs_to_a++;
				}
			}
			while (!is_sorted(stack_a))
			{
				if(pushs_to_a == 2)
				{
					swap(stack_a);
					pushs_to_a++;
				}
				else
				{
					mid = get_mid_chunk_a(stack_a, pushs_to_a);
					recalc_chunk(stack_a, stack_b, chunks, mid, pushs_to_a);
				}
			}
		}
 	}
	if (chunks->stack[chunks->top] == 0)
		chunks->top--;
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	mid;
	t_stack	*chunks;

	chunks = create_stack(capacity_chunk(stack_a->capacity), 'c');
	while (stack_a->top > 1 && !is_sorted(stack_a))
	{
		mid = get_mid(stack_a);
		printf("mid: %d\n", mid);
		chunks->top++;
		chunks->stack[chunks->top] = get_chunk(stack_a, stack_b, mid);
	}
	sorting_last_items(stack_a, stack_b, chunks);
	printf("começo da logica da B\n");
	while (stack_b->top > -1)
	{
		if (is_b_sorted(stack_b))
			push(stack_b, stack_a);
		else
			move_chunk(stack_a, stack_b, chunks);
	}
	free(chunks->stack);
	free(chunks);
}
