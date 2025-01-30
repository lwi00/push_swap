/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sequence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:57:29 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 15:57:30 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	markup_init(t_node **stack_a)
{
	t_node	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		node->value = 0;
		node = node->next;
	}
	node->value = 0;
}

void	markup(t_node **stack_a, t_seq *seq)
{
	t_node	*node;
	t_node	*next;
	int		i;

	markup_init(stack_a);
	i = 0;
	node = *stack_a;
	while (i++ < seq->max_index)
		next = node->next;
	node->value = 1;
	i = node->index;
	next = node->next;
	seq->start = node->index;
	while (next->next != *stack_a)
	{
		if (i == next->index - 1)
		{
			next->value = 1;
			i = next->index;
		}
		next = next->next;
	}
	if (i == next->index - 1)
		next->value = 1;
}

t_seq	*seq_init(t_seq **seq)
{
	(*seq) = malloc(sizeof(t_seq));
	(*seq)->max_len = 0;
	(*seq)->curr_len = 1;
	return (*seq);
}

void	create_sequence(t_node *node, t_seq **seq, int i, t_node **stack)
{
	t_node	*it;
	int		prev;

	it = node->next;
	prev = node->index;
	(*seq)->curr_len = 0;
	(*seq)->index = i;
	while (it->next != *stack)
	{
		if (prev == it->index - 1)
		{
			(*seq)->curr_len++;
			prev = it->index;
		}
		it = it->next;
	}
	if (prev == it->index - 1)
		(*seq)->curr_len++;
	it = it->next;
	if ((*seq)->curr_len > (*seq)->max_len)
	{
		(*seq)->max_len = (*seq)->curr_len;
		(*seq)->max_index = (*seq)->index;
	}
}

t_seq	*sequence(t_node **stack)
{
	t_seq	*seq;
	t_node	*node;
	int		i;

	seq = seq_init(&seq);
	node = *stack;
	i = 0;
	while (node->next != *stack)
	{
		create_sequence(node, &seq, i, stack);
		node = node->next;
		i++;
	}
	return (seq);
}
