/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:56:28 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:56:36 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_node **stack, int a)
{
	t_node	*node;

	node = *stack;
	if (!node)
		return ;
	if (node->next == *stack && node->prev == *stack)
		return ;
	if (node->next->next == *stack && node->prev == *stack)
	{
		sa(stack, 0);
		return ;
	}
	*stack = (*stack)->next;
	if (a)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack, int a)
{
	t_node	*node;

	node = *stack;
	if (!node)
		return ;
	if (node->next == *stack && node->prev == *stack)
		return ;
	if (node->next->next == *stack && node->prev == *stack)
	{
		sa(stack, 0);
		return ;
	}
	*stack = (*stack)->next;
	if (a)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
