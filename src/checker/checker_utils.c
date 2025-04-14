/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:50:25 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/25 11:45:19 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	parse_command(t_stack **a, t_stack **b, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		pa(a, b, false);
	else if (ft_strcmp(command, "pb\n") == 0)
		pb(b, a, false);
	else if (ft_strcmp(command, "sa\n") == 0)
		sa(a, false);
	else if (ft_strcmp(command, "sb\n") == 0)
		sb(b, false);
	else if (ft_strcmp(command, "ss\n") == 0)
		ss(a, b, false);
	else if (ft_strcmp(command, "ra\n") == 0)
		ra(a, false);
	else if (ft_strcmp(command, "rb\n") == 0)
		rb(b, false);
	else if (ft_strcmp(command, "rr\n") == 0)
		rr(a, b, false);
	else if (ft_strcmp(command, "rra\n") == 0)
		rra(a, false);
	else if (ft_strcmp(command, "rrb\n") == 0)
		rrb(b, false);
	else if (ft_strcmp(command, "rrr\n") == 0)
		rrr(a, b, false);
	else
		error(a, b);
}

int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

void	error(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	check_and_print_result(t_stack *a, int len)
{
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}
