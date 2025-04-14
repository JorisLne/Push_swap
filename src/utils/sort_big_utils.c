/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:57:37 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/24 14:11:33 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	set_current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (stack == NULL)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

//nodes in b gets target node in a
void	set_target_node(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_index)
			{
				best_match_index = current_a->nbr;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	if (!a || !b)
		return ;
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		if (!b->target_node)
			return ;
		b->push_cost = b->index;
		if (!(b->above_median))
			b->push_cost = len_b - (b->index);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (b == NULL)
		return ;
	cheapest_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < cheapest_value)
		{
			cheapest_value = b->push_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	cheapest_node->cheapest = true;
}

void	set_node_targets_and_costs(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	set_current_index(a);
	set_current_index(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}
