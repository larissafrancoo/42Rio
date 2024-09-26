/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:07:37 by larissa           #+#    #+#             */
/*   Updated: 2024/04/23 18:07:39 by larissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stk_size(t_node *head)
{
	int	ssize;

	ssize = 0;
	while (head)
	{
		ssize++;
		head = head->next;
	}
	return (ssize);
}

void	push(t_node **src_stack, t_node **dest_stack)
{
	t_node	*tmp;

	if (stk_size(*src_stack) == 0)
		return ;
	tmp = *src_stack;
	*src_stack = (*src_stack)->next;
	push_on(dest_stack, tmp);
}

void	swap(t_node **stack)
{
	t_node	*tmp;

	if (stk_size(*stack) < 2)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*head;

	if (stk_size(*stack) < 2)
		return ;
	tail = last_node(*stack);
	head = *stack;
	*stack = (*stack)->next;
	tail->next = head;
	head->next = NULL;
}

void	rev_rotate(t_node **stack)
{
	t_node	*tail;
	t_node	*pre_tail;

	if (stk_size(*stack) < 2)
		return ;
	pre_tail = *stack;
	while (pre_tail->next->next)
		pre_tail = pre_tail->next;
	tail = pre_tail->next;
	pre_tail->next = NULL;
	tail->next = *stack;
	*stack = tail;
}
