/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:37:19 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/22 18:41:51 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	duplicate_error(char **av, long n, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (n == ft_atol(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	syntax_error(char *str)
{
	if (!(*str == '+' || *str == '-' || (*str >= '0' && *str <= '9')))
		return (1);
	if ((*str == '+' || *str == '-') && !(str[1] >= '0' && str[1] <= '9'))
		return (1);
	str++;
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9'))
			return (1);
		str++;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		(*stack)->nbr = 0;
		free(*stack);
		*stack = tmp;
	}
}

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	check_input(char **av)
{
	int		i;
	long	n;

	i = 0;
	while (av[i])
	{
		if (syntax_error(av[i]))
			return (1);
		n = ft_atol(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (1);
		if (duplicate_error(av, (int)n, i))
			return (1);
		i++;
	}
	return (0);
}
