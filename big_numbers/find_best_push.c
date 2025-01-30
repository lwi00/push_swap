/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:57:35 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:57:36 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_one(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;
	t_node	*mem;
	int		max_moves;

	max_moves = 2147483647;
	node = *stack_b;
	while (node->next != *stack_b)
	{
		if (node->sa + node->sb + node->ra + node->rb + node->rra
			+ node->rrb < max_moves)
		{
			max_moves = node->sa + node->sb + node->ra + node->rb + node->rra
				+ node->rrb;
			mem = node;
		}
		node = node->next;
	}
	if (node->sa + node->sb + node->ra + node->rb + node->rra
		+ node->rrb < max_moves)
	{
		max_moves = node->sa + node->sb + node->ra + node->rb + node->rra
			+ node->rrb;
		mem = node;
	}
	do_moves(stack_a, stack_b, &mem);
}

void	find_best_push(t_node **stack_a, t_node **stack_b)
{
	t_node	*b;
	int		i;
	int		size;

	b = *stack_b;
	i = 0;
	size = stack_size(*stack_b);
	while (b->next != *stack_b)
	{
		if (i <= size / 2)
			b->rb = i;
		else
			b->rrb = size - i;
		prepare_stack_a(stack_a, &b);
		i++;
		b = b->next;
	}
	if (i <= size / 2)
		b->rb = i;
	else
		b->rrb = size - i;
	prepare_stack_a(stack_a, &b);
	push_one(stack_a, stack_b);
}
