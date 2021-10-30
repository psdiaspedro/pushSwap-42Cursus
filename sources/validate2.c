/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:13:06 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/29 16:09:23 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 1)
	{
		if(stack->stack[i] < stack->stack[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}

int	is_b_sorted(t_stack *stack)
{
	int	i;

	i = stack->top;
	while (i >= 1)
	{
		if(stack->stack[i] > stack->stack[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
}
