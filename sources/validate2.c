/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 11:13:06 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 16:02:05 by pedroadias       ###   ########.fr       */
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

int	is_chunk_sorted(t_stack *stack, int len)
{
	int	*copy;
	int	i;
	int	j;

	copy = malloc(sizeof(int) * len);
	i = stack->top + 1 - len;
	j = 0;
	while (i <= stack->top)
	{
		copy[j] = stack->stack[i++];
		j++;
	}
	i = len - 1;
	while (i >= 1)
	{
		if(copy[i] > copy[i - 1])
			i--;
		else
		{
			free(copy);
			return (0);
		}
	}
	free(copy);
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

int	is_mid_higher(t_stack *stack, t_stack *chunks, int mid)
{
	int	*copy;
	int	i;
	int	j;

	copy = malloc(sizeof(int) * chunks->stack[chunks->top]);
	i = stack->top + 1 - chunks->stack[chunks->top];
	j = 0;
	while (i <= stack->top)
	{
		copy[j] = stack->stack[i++];
		j++;
	}
	i = 0;
	while (i <= j)
	{
		if (copy[i] <= mid)
			i++;
		else
		{
			free(copy);
			return (0);
		}
	}
	free(copy);
	return (1);
}
