/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaine <jlaine@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:41:51 by jlaine            #+#    #+#             */
/*   Updated: 2024/07/25 12:38:16 by jlaine           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define BUFFER_SIZE 42

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			cheapest;
	bool			above_median;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// errors
void	print_error(void);
void	free_stack(t_stack **stack);
int		check_input(char **av);
int		syntax_error(char *str);
int		duplicate_error(char **av, long n, int index);

// commands
void	sa(t_stack **a, bool checker);
void	sb(t_stack **b, bool checker);
void	ra(t_stack **a, bool checker);
void	rb(t_stack **b, bool checker);
void	rra(t_stack **a, bool checker);
void	rrb(t_stack **b, bool checker);
void	ss(t_stack **a, t_stack **b, bool checker);
void	rr(t_stack **a, t_stack **b, bool checker);
void	pa(t_stack **a, t_stack **b, bool checker);
void	pb(t_stack **b, t_stack **a, bool checker);
void	rrr(t_stack **a, t_stack **b, bool checker);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

// init stack
char	**ft_split(char *s, char c);
long	ft_atol(const char *str);
void	free_split(char **split_result);
void	add_node(t_stack **stack, int n);
void	init_stack_a(t_stack **a, char **av);

// stack utils
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_highest(t_stack *stack);
t_stack	*find_last(t_stack *stack);
int		stack_len(t_stack *stack);
bool	stack_sorted(t_stack *stack);

// sort big utils
void	set_cheapest(t_stack *b);
t_stack	*return_cheapest(t_stack *stack);
void	set_current_index(t_stack *stack);
void	set_price(t_stack *a, t_stack *b);
void	move_nodes(t_stack **a, t_stack **b);
void	set_target_node(t_stack *a, t_stack *b);
void	set_node_targets_and_costs(t_stack *a, t_stack *b);
void	finish_rotation(t_stack **stack, t_stack *top_node, char stack_name);

// algos
void	sort_three(t_stack **a);
void	sort_big(t_stack **a, t_stack **b);

// checker
char	*get_next_line(int fd);
void	error(t_stack **a, t_stack **b);
int		ft_strcmp(char *str_1, char *str_2);
void	check_and_print_result(t_stack *a, int len);
void	parse_command(t_stack **a, t_stack **b, char *command);

// checker utils
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif