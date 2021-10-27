/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:01:31 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 14:01:31 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


t_stack	*create_stack(int capacity, char c)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->capacity = capacity;
	stack->top = -1;
	stack->stack = malloc(capacity * sizeof(int));
	stack->c = c;

	return (stack);
}

int	*init_copy(int *array, int start, int end)
{
	int	*copy;
	int	i;
	int j;
	int len;

	len = end - start + 1;
	copy = malloc(sizeof(int) * len);
	i = end;
	j = len - 1;
	while (j >= 0)
	{
		copy[j] = array[i];
		i--;
		j--;
	}
	return (copy);
}

void	init_stack(t_stack *stack , char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = stack->capacity - 1;
	while (j >= 0)
	{
		stack->stack[j] = ft_atoi(argv[i]);
		stack->top++;
		i++;
		j--;
	}
}
