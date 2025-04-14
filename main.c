/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 14:39:32 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/23 14:24:13 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_len(*a) == 2)
		sa(a, true);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else
		sort_big(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
		av = ft_split(av[1], ' ');
	else
		av = av + 1;
	if (check_input(av))
	{
		if (ac == 2)
			free_split(av);
		print_error();
	}
	init_stack_a(&a, av);
	if (!stack_sorted(a))
		sort_stack(&a, &b);
	if (ac == 2)
		free_split(av);
	free_stack(&a);
	return (0);
}
