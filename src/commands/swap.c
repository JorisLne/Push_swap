/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 16:43:36 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/23 14:24:03 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap(t_stack **head)
{
	int	len;

	len = stack_len(*head);
	if (*head == NULL || head == NULL || len == 1)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack **a, bool should_print)
{
	swap(a);
	if (should_print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, bool should_print)
{
	swap(b);
	if (should_print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, bool should_print)
{
	swap(a);
	swap(b);
	if (should_print)
		write(1, "ss\n", 3);
}
