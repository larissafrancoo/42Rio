/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:04:33 by lfranco           #+#    #+#             */
/*   Updated: 2024/05/01 05:36:17 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mv_etc(t_node **stack_a, t_node **stack_b, int b)
{
	int	size;
	int	op;

	op = 0;
	size = stk_size(*stack_a) + 1;
	while (--size > 0)
	{
		if (!((*stack_a)->index & b))
		{
			px(stack_a, stack_b, 'b');
			op++;
		}
		else
			rx(stack_a, 'a');
	}
	while (op > 0)
	{
		px(stack_b, stack_a, 'a');
		op--;
	}
}

void	radix_sort(t_node **stack_a, t_node **stack_b)
{
	int	b;

	b = 1;
	while (!check_stk_sort(stack_a))
	{
		mv_etc(stack_a, stack_b, b);
		b = b << 1;
	}
}

static void	sorting(int ac, t_node **stack_a, t_node **stack_b)
{
	if (ac < 7)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_node	**stack_a;
	t_node	**stack_b;

	checker_input(ac, av);
	stack_a = (t_node **) malloc(sizeof(t_node *));
	stack_b = (t_node **) malloc(sizeof(t_node *));
	if (!stack_a || !stack_b)
		return (0);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, av);
	sorting(ac, stack_a, stack_b);
	stk_free(stack_a);
	stk_free(stack_b);
	return (0);
}
