/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 12:12:28 by lfranco           #+#    #+#             */
/*   Updated: 2024/05/01 03:46:43 by lfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_nude
{
	int				index;
	int				number;
	struct s_nude	*next;
}				t_node;

void	radix_sort(t_node **stack_a, t_node **stack_b);
void	checker_input(int ac, char **av);
int		check_stk_sort(t_node **stack);
void	init_stack(t_node **stack, char **av);
void	index_stack(t_node **stack);
t_node	*node_maker(int nu);
int		min(t_node **stack, int n);
t_node	*last_node(t_node *head);
void	push_under(t_node **stack, t_node *new_node);
void	push_on(t_node **stack, t_node *new_node);
int		stk_size(t_node *head);
void	push(t_node **src_stack, t_node **dest_stack);
void	swap(t_node **stack);
void	rotate(t_node **stack);
void	rev_rotate(t_node **stack);
void	rx(t_node **stack, int c);
void	rr(t_node **stack_a, t_node **stack_b);
void	rrx(t_node **stack, int c);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sx(t_node **stack, int c);
void	ss(t_node **stack_a, t_node **stack_b);
void	px(t_node **stack1, t_node **stack2, int c);
void	put_error(char *m);
void	stk_free(t_node **stack);
void	simple_sort(t_node **stack_a, t_node **stack_b);
int		find_index_node(t_node **stack, int i);

#endif
