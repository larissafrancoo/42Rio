/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:32:16 by larissa           #+#    #+#             */
/*   Updated: 2024/04/24 17:56:54 by larissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_node(t_node **stack, int i)
{
	t_node	*head;
	int		node_position;

	head = *stack;
	node_position = 0;
	while (head)
	{
		if (head->index == i)
			break ;
		node_position++;
		head = head->next;
	}
	return (node_position);
}

static void	three_n(t_node **stack_a)
{
	if ((*stack_a)->index == min(stack_a, -1)
		&& (*stack_a)->next->index != min(stack_a, min(stack_a, -1)))
	{
		rx(stack_a, 'a');
		sx(stack_a, 'a');
		rrx(stack_a, 'a');
	}
	else if ((*stack_a)->index == min(stack_a, min(stack_a, -1)))
	{
		if ((*stack_a)->next->index == min(stack_a, -1))
			sx(stack_a, 'a');
		else
			rrx(stack_a, 'a');
	}
	else
	{
		if ((*stack_a)->next->index == min(stack_a, -1))
			rx(stack_a, 'a');
		else
		{
			sx(stack_a, 'a');
			rrx(stack_a, 'a');
		}
	}
}

static void	four_n(t_node **stack_a, t_node **stack_b)
{
	int	position;

	position = find_index_node(stack_a, min(stack_a, -1));
	if (position == 1)
		rx(stack_a, 'a');
	else if (position == 2)
	{
		rx(stack_a, 'a');
		rx(stack_a, 'a');
	}
	else if (position == 3)
		rrx(stack_a, 'a');
	if (check_stk_sort(stack_a))
		return ;
	px(stack_a, stack_b, 'b');
	three_n(stack_a);
	px(stack_b, stack_a, 'a');
}

static void	five_n(t_node **stack_a, t_node **stack_b)
{
	int	position;

	position = find_index_node(stack_a, min(stack_a, -1));
	if (position == 1)
		rx(stack_a, 'a');
	else if (position == 2)
	{
		rx(stack_a, 'a');
		rx(stack_a, 'a');
	}
	else if (position == 3)
	{
		rrx(stack_a, 'a');
		rrx(stack_a, 'a');
	}
	else if (position == 4)
		rrx(stack_a, 'a');
	if (check_stk_sort(stack_a))
		return ;
	px(stack_a, stack_b, 'b');
	four_n(stack_a, stack_b);
	px(stack_b, stack_a, 'a');
}

void	simple_sort(t_node **stack_a, t_node **stack_b)
{
	int	size;

	size = stk_size(*stack_a);
	if (size == 2)
		sx(stack_a, 'a');
	else if (size == 3)
		three_n(stack_a);
	else if (size == 4)
		four_n(stack_a, stack_b);
	else if (size == 5)
		five_n(stack_a, stack_b);
}
