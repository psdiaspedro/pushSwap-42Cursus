/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedroadias <pedroadias@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 16:08:51 by pedroadias        #+#    #+#             */
/*   Updated: 2021/10/27 11:13:16 by pedroadias       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


static int	is_integer(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-')
				j++;
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	is_in_range(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > MAX_INT || ft_atol(argv[i]) < MIN_INT)
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(char **argv)
{
	int	holder;
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		holder = ft_atoi(argv[i]);
		while (argv[j])
		{
			if(holder == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	validate(char **argv)
{
	if (is_integer(argv) && is_in_range(argv) && is_duplicate(argv))
		return (1);
	return (0);
}
