/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:13:06 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 11:13:54 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_sorted(t_stack *stack) //1 2 3
{
	int	i;

	i = stack->top; //8
	while (i >= 1)
	{
		if(stack->stack[i] < stack->stack[i - 1])
			i--;
		else
			return (0);
	}
	return (1);
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
