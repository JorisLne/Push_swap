/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:47:28 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/24 14:51:32 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = return_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, true);
}

t_stack	*return_cheapest(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, true);
			else
				rra(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	int		len_a;
	t_stack	*smallest;

	len_a = stack_len(*a);
	while (len_a-- > 3)
		pb (b, a, true);
	sort_three(a);
	while (*b)
	{
		if (*b == NULL)
			break ;
		set_node_targets_and_costs(*a, *b);
		move_nodes(a, b);
	}
	set_current_index(*a);
	smallest = find_smallest(*a);
	while (*a != smallest)
	{
		if (smallest->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
}
