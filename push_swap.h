/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldoidy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:54:54 by ldoidy            #+#    #+#             */
/*   Updated: 2025/01/13 23:07:24 by ldoidy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			nb;
	int			index;
	struct node	*next;
	struct node	*prev;
	int			value;
	int			sa;
	int			sb;
	int			ra;
	int			rb;
	int			rra;
	int			rrb;
	int			move;
}				t_node;

typedef struct seq
{
	int			curr_len;
	int			max_len;
	int			index;
	int			max_index;
	int			start;
}				t_seq;

typedef struct max
{
	int			nb;
	int			size;
}				t_max;

t_node			*stack_a_init(t_node *stack, char **array);
t_node			*create_node(int value);
void			pile_down(t_node *stack, t_node *node);
int				stack_size(t_node *stack);
int				*stack_dup(int *array, t_node *stack);
void			quicksort(t_node *stack, int *array, int start, int end);
void			index_init(t_node *stack);
void			printer(t_node *stack);
void			array_printer(int *array, int size);
void			index_printer(t_node *stack);
void			sa(t_node **stack, int a);
void			sb(t_node **stack, int a);
void			ra(t_node **stack, int a);
void			rb(t_node **stack, int a);
void			rr(t_node **stack_a, t_node **stack_b);
void			rra(t_node **stack, int a);
void			rrb(t_node **stack, int a);
void			rrr(t_node **stack_a, t_node **stack_b);
void			pb(t_node **stack_a, t_node **stack_b);
void			pa(t_node **stack_a, t_node **stack_b);
void			sort_three_numbers(t_node **stack);
void			sort_five_numbers(t_node **stack_a, t_node **stack_b);
void			big_sort(t_node **stack_a, t_node **stack_b);
t_seq			*sequence(t_node **stack);
void			moves_printer(t_node **stack);
void			moves_init(t_node **stack_a, int n);
void			sort_three_numbers(t_node **stack);
void			markup(t_node **stack_a, t_seq *seq);
char			**args_handler(int *ac, char **av);
int				is_max(t_node *stack_a, t_node *b);
void			do_moves(t_node **stack_a, t_node **stack_b, t_node **node);
void			find_best_push(t_node **stack_a, t_node **stack_b);
void			prepare_stack_a(t_node **stack_a, t_node **b);
void			ft_free_stack(t_node **stack, int size);
void			ft_free_array(char **array);
int				ft_array_size(char **array);
void			error(void);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
int				ft_atoi(const char *str);
void			ft_swap(int *a, int *b);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *s);

#endif
