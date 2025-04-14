/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:43:26 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/23 14:23:24 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	int		len;
	t_stack	*last_node;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack **a, bool should_print)
{
	reverse_rotate(a);
	if (should_print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, bool should_print)
{
	reverse_rotate(b);
	if (should_print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, bool should_print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (should_print)
		write(1, "rrr\n", 4);
}

void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, true);
	set_current_index(*a);
	set_current_index(*b);
}
