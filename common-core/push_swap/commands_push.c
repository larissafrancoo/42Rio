/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:06:52 by lfranco           #+#    #+#             */
/*   Updated: 2024/04/24 12:25:17 by larissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	push_on(t_node	**stack, t_node *new_node)
{
	if (!new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}

void	push_under(t_node **stack, t_node *new_node)
{
	t_node	*tmp;

	if (!new_node)
		return ;
	if (*stack)
	{
		tmp = last_node(*stack);
		tmp->next = new_node;
	}
	else
		*stack = new_node;
}
