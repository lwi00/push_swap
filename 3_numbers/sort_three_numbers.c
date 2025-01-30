/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:58:07 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:58:11 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	case_check(t_node *stack)
{
	if ((stack->nb < stack->next->nb) && (stack->next->nb < stack->prev->nb))
		return (1);
	else if ((stack->nb > stack->next->nb)
		&& (stack->next->nb < stack->prev->nb) && (stack->prev->nb > stack->nb))
		return (2);
	else if ((stack->nb > stack->next->nb)
		&& (stack->next->nb > stack->prev->nb) && (stack->prev->nb < stack->nb))
		return (3);
	else if ((stack->nb > stack->next->nb)
		&& (stack->next->nb < stack->prev->nb) && (stack->prev->nb < stack->nb))
		return (4);
	else if ((stack->nb < stack->next->nb)
		&& (stack->next->nb > stack->prev->nb) && (stack->prev->nb > stack->nb))
		return (5);
	else
		return (6);
}

void	sort_three_numbers(t_node **stack)
{
	if (stack_size(*stack) == 2 && (*stack)->nb > (*stack)->next->nb)
	{
		sa(stack, 1);
		return ;
	}
	if (case_check(*stack) == 1)
		return ;
	else if (case_check(*stack) == 2)
		sa(stack, 1);
	else if (case_check(*stack) == 3)
	{
		ra(stack, 1);
		sa(stack, 1);
	}
	else if (case_check(*stack) == 4)
		ra(stack, 1);
	else if (case_check(*stack) == 5)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else
		rra(stack, 1);
}
