/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:44:05 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/21 16:58:11 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_stack
{
	int capacity; //capacidade total da pilha
	int top; //topo da pilha
	int *stack; //ponteiro paro a pilha
}	t_stack;

void	init_stack(t_stack *stack , char **argv);
t_stack	*create_stack(int capacity);
int		validate(char **argv);
#endif
