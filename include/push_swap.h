/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malauzie <malauzie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 11:45:50 by malauzie          #+#    #+#             */
/*   Updated: 2023/12/19 17:48:40 by malauzie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;

	bool			above_median;
	bool			cheapest_push;

	struct s_stack	*previous;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

/*------------------------------init_stack------------------------------------*/
void	add_new_node(int value, t_stack **a);
void	init_stack(char **argv, t_stack **a, int i);

/*------------------------check_and_convert_input-----------------------------*/
bool	is_digit(char *str);
bool	is_not_double(char **argv, char *str, int j);
int		str_to_int(char *str);

/*----------------------------handle_errors-----------------------------------*/
void	free_stack(t_stack **stack);
void	free_and_print_error(char **argv, t_stack **a, int is_split);

/*-----------------------------sort_stack-------------------------------------*/
bool	stack_is_sorted(t_stack *stack);
void	sort_three_nodes(t_stack **a);
void	init_stack_index(t_stack *stack);
void	do_last_moves(t_stack **stack, t_stack *head_node, char id);
void	sort_stack(t_stack **a, t_stack **b);

/*----------------------------instructions------------------------------------*/
void	push(t_stack **stack_src, t_stack **stack_dest);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

/*-----------------------------move_a_to_b------------------------------------*/
void	find_closest_smaller_node(t_stack *a, t_stack *b);
void	count_moves(t_stack *a, t_stack *b);
t_stack	*find_cheapest_push(t_stack *a);
t_stack	*set_a_ready_to_push(t_stack *a, t_stack *b);
void	move_a_to_b(t_stack **a, t_stack **b);

/*-----------------------------move_b_to_a------------------------------------*/
void	find_closest_bigger_node(t_stack *a, t_stack *b);
void	move_b_to_a(t_stack **a, t_stack **b);

/*-----------------------------chained_list-----------------------------------*/
t_stack	*find_last_node(t_stack *a);
int		count_nodes(t_stack *stack);
t_stack	*find_max_node(t_stack *stack);
t_stack	*find_min_node(t_stack *stack);

/*-------------------------------strings--------------------------------------*/
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*------------------------------ft_split--------------------------------------*/
int		ft_count_bloc(char const *s, char c);
char	*malloc_str(char **tab, int j, int count_char);
char	**ft_count_char(char const *s, char c, char **tab, int size);
char	**ft_split(char const *s, char c);

#endif