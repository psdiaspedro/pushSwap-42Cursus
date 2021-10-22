/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:38:47 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/22 14:47:51 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	printf("----- STACK A -----\n");
	for(int i = stack_a->top; i >= 0; i--)
		printf("%d\n", stack_a->stack[i]);
	printf("----- STACK B -----\n");
	for(int i = stack_b->top; i >= 0; i--)
		printf("%d\n", stack_b->stack[i]);
	printf("\n");
	double_reverse_rotate(stack_a, stack_b);
	printf("----- STACK A -----\n");
	for(int i = stack_a->top; i >= 0; i--)
		printf("%d\n", stack_a->stack[i]);
	printf("----- STACK B -----\n");
	for(int i = stack_b->top; i >= 0; i--)
		printf("%d\n", stack_b->stack[i]);
	printf("\n");
}
