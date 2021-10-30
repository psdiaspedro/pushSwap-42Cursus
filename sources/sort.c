/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:38:47 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/29 21:29:45 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	// printf("----- STACK A BEFORE SORT-----\n");
	// for(int i = stack_a->top; i >= 0; i--)
    //     printf("%d\n", stack_a->stack[i]);
	// puts("\n");
	// printf("----- STACK B BEFORE SORT-----\n");
	// for(int i = stack_b->top; i >= 0; i--)
    //     printf("%d\n", stack_b->stack[i]);
	// puts("\n");
	if (is_sorted(stack_a))
		return ;
	if (stack_a->capacity == 2)
		swap(stack_a);
	else if (stack_a->capacity <= 5)
		simple_sort(stack_a, stack_b);
	else
		complex_sort(stack_a, stack_b);
	// printf("----- STACK A AFTER SORT-----\n");
	// for(int i = stack_a->top; i >= 0; i--)
    //     printf("%d\n", stack_a->stack[i]);
	// puts("\n");
	// printf("----- STACK B AFTER SORT-----\n");
	// for(int i = stack_b->top; i >= 0; i--)
    //     printf("%d\n", stack_b->stack[i]);
	// puts("\n");
}
