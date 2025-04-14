/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:25:23 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/24 12:55:26 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	add_node(t_stack **stack, int n)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (stack == NULL)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		return ;
	new_node->next = NULL;
	new_node->nbr = n;
	if (*stack == NULL)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	init_stack_a(t_stack **a, char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		n = ft_atol(av[i]);
		add_node(a, (int)n);
		++i;
	}
}
