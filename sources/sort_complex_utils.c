/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:21:51 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/28 16:04:43 by pedroadias       ###   ########.fr       */
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

int	get_mid_chunk_a(t_stack *stack, int len)
{
	int	*copy;
	int	mid;

	copy = init_copy(stack->stack, stack->top - len, stack->top);
	mid = insertion_sort(copy, len);
	free(copy);
	return (mid);
}
