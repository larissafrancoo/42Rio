/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larissa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:07:08 by larissa           #+#    #+#             */
/*   Updated: 2024/04/24 02:02:10 by larissa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_node **stack, char **av)
{
	t_node	*nude;
	int		i;

	i = 1;
	while (av[i])
	{
		nude = node_maker(ft_atol(av[i]));
		push_under(stack, nude);
		i++;
	}
	index_stack(stack);
}

t_node	*node_maker(int nu)
{
	t_node	*node;

	node = (t_node *) malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->number = nu;
	node->index = -1;
	node->next = NULL;
	return (node);
}

static t_node	*next_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		flag;

	head = *stack;
	min = NULL;
	flag = 0;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!flag || head->number < min->number))
			{
				min = head;
				flag = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_node **stack)
{
	t_node	*head;
	int		i;

	i = 0;
	head = next_min(stack);
	while (head)
	{
		head->index = i++;
		head = next_min(stack);
	}
}

int	min(t_node **stack, int n)
{
	t_node	*head;
	int		min_idx;

	head = *stack;
	min_idx = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min_idx) && head->index != n)
			min_idx = head->index;
	}
	return (min_idx);
}
