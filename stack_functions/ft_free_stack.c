/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:56:53 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:56:56 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_node **stack, int size)
{
	t_node	*node;
	int		i;

	i = 0;
	node = *stack;
	while (i < size - 1)
	{
		node = node->next;
		free(node->prev);
		i++;
	}
	free(node);
}
