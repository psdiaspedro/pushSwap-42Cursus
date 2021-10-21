/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:44:01 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/21 17:03:00 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;

	if(argc < 2)
		return (0);
	if(!validate(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack(argc - 1);
	stack_b = create_stack(argc - 1);
	init_stack(stack_a, argv);
	return (0);
}


