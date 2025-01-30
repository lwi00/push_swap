/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:57:40 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:57:41 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_moves_2(t_node **stack_a, t_node **stack_b, t_node **node)
{
	while ((*node)->rra && (*node)->rrb)
	{
		rrr(stack_a, stack_b);
		(*node)->rra--;
		(*node)->rrb--;
	}
	while ((*node)->rra)
	{
		rra(stack_a, 1);
		(*node)->rra--;
	}
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}
	pa(stack_a, stack_b);
}

void	do_moves_1(t_node **stack_a, t_node **stack_b, t_node **node)
{
	while ((*node)->ra && (*node)->rb)
	{
		rr(stack_a, stack_b);
		(*node)->ra--;
		(*node)->rb--;
	}
	while ((*node)->ra)
	{
		ra(stack_a, 1);
		(*node)->ra--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	pa(stack_a, stack_b);
}

void	do_moves(t_node **stack_a, t_node **stack_b, t_node **node)
{
	if ((*node)->move == 1)
		do_moves_1(stack_a, stack_b, node);
	else if ((*node)->move == 2)
		do_moves_2(stack_a, stack_b, node);
}
