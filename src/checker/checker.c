/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 11:50:28 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/25 12:36:24 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	handle_inputs_checker(int ac, char **av, t_stack **a)
{
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return ;
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
	init_stack_a(a, av);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		len;
	char	*next_line;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	handle_inputs_checker(ac, av, &a);
	len = stack_len(a);
	write(1, "Enter sorting instructions (one per line), ", 43);
	write(1, "Press Ctrl+D when finished.\n", 28);
	write(1, "Enjoy :)\n", 9);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	check_and_print_result(a, len);
	return (0);
}
