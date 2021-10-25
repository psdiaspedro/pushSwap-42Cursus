/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:31:43 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/25 14:52:38 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	simple_sort(t_stack *stack)
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
