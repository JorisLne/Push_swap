/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:43:31 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/23 14:23:49 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotate(t_stack **stack)
{
	int		len;
	t_stack	*last_node;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack **a, bool should_print)
{
	rotate(a);
	if (should_print)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, bool should_print)
{
	rotate(b);
	if (should_print)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, bool should_print)
{
	rotate(a);
	rotate(b);
	if (should_print)
		write(1, "rr\n", 3);
}

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, true);
	set_current_index(*a);
	set_current_index(*b);
}
