/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:46 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/30 18:30:23 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	do_movements(t_stack *stack_a, t_stack *stack_b, int idx_a, int idx_b)
{
	int	next_top;

	next_top = stack_b->top - 1;
	while (stack_b->top != next_top)
	{
		if (idx_a >= stack_a->top / 2 && idx_b >= stack_b->top / 2)
			moves_one(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a < stack_a->top / 2 && idx_b < stack_b->top / 2)
			moves_two(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a >= stack_a->top / 2 && idx_b < stack_b->top / 2)
			moves_three(stack_a, stack_b, idx_a, idx_b);
		else if (idx_a < stack_a->top / 2 && idx_b >= stack_b->top / 2)
			moves_four(stack_a, stack_b, idx_a, idx_b);
	}
}

void	send_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	moves;
	int	i;
	int	pos_b;

	i = stack_b->top + 1;
	pos_b = stack_b->top;
	moves = stack_a->capacity * 2;
	while (--i >= 0)
	{
		if (i >= stack_b->top / 2
			&& get_moves(stack_a, stack_b->stack[i]) + stack_b->top - i < moves)
		{
			pos_b = i;
			moves = get_moves(stack_a, stack_b->stack[i]) + stack_b->top - i;
		}
		else if (i < stack_b->top / 2
			&& (get_moves(stack_a, stack_b->stack[i]) + (i + 1)) < moves)
		{
			pos_b = i;
			moves = get_moves(stack_a, stack_b->stack[i]) + (i + 1);
		}
	}
	i = get_position (stack_a, moves, stack_b->stack[pos_b]);
	do_movements(stack_a, stack_b, i, pos_b);
}

void	complex_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	smaller;
	int	higher;

	smaller = find_smaller(stack_a);
	higher = find_higher(stack_a);
	while (!is_sorted(stack_a))
	{
		if ((stack_a->stack[stack_a->top] < stack_a->stack[stack_a->top - 1]
				&& stack_a->stack[stack_a->top] > stack_a->stack[0])
			|| stack_a->stack[stack_a->top] == smaller
			|| stack_a->stack[stack_a->top] == higher)
			rotate(stack_a);
		else
			push(stack_a, stack_b);
	}
	while (stack_b->top >= 0)
	{
		send_back_to_a(stack_a, stack_b);
	}
	while (!is_sorted(stack_a))
		moves_five(stack_a);
}
