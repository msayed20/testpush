/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhelal <suhelal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 12:31:32 by suhelal           #+#    #+#             */
/*   Updated: 2024/03/14 10:29:39 by suhelal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>

typedef struct stack
{
	int						data;
	struct stack			*next;
	struct target_node 		*target;
	struct moves_node		*inst;
	struct cheapest_node 	*cheapest;
	
}				stack_list;

typedef struct target_node
{
	int			max_stack_b;
	int			min_stack_b;
	int 		max_stack_a;
	int 		min_stack_a;
}				target_node;

typedef struct moves_node
{
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int 	rrr;
	int		pb;
	int		pa;
}			moves_node;

typedef struct cheapest_node
{
	int		total;
	int		sa;
	int		sb;
	int		ss;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int 	rrr;
	int		pb;
	int		pa;
}			cheapest_node;

/*PARSING*/
char		**split_arg(char const *s);
stack_list 	*create_stack(stack_list **a, char **str);
void 		ft_printList(stack_list *head);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
void 		check_arg(int c, char **av);
char		*join_arg(int c, char **av);
char		*ft_strdup(const char *s1);
int			ft_strcmp(char *s1, char *s2);
int 		conv_num(const char *str);

/*FREE FUNCTIONS AND ERROR*/
void 		free_str(char *str);
void		ft_handle_free(char **ptr);
void 		ft_free_list(stack_list **list);
void 		last_free_list(stack_list **list);
void    	error_write(void);

/*INSTRCUTIONS*/
void 	ft_sa(stack_list **a);
void 	ft_sb(stack_list **b);
void 	ft_ss(stack_list **a, stack_list **b);
void 	ft_ra(stack_list **a);
void 	ft_rb(stack_list **b);
void 	ft_rr(stack_list **a, stack_list **b);
void	ft_rra(stack_list **a);
void    ft_rrb(stack_list **b);
void 	ft_rrr(stack_list **a, stack_list **b);
void    ft_pa(stack_list **a, stack_list **b);
void    ft_pb(stack_list **a, stack_list **b);
void 	write_inst_swap(stack_list **a, stack_list **b, char *str);
void 	write_inst_rotate(stack_list **a, stack_list **b, char *str);
void 	write_inst_reverse_rotate(stack_list **a, stack_list **b, char *str);

/*SORTING*/
int			lst_len(stack_list **lst);
stack_list	*list_last(stack_list **a);
int 		list_position(stack_list **stack, int num);
stack_list 	*ft_sort(stack_list **a, stack_list **b);
stack_list  *sort_three(stack_list **a, stack_list **b);
stack_list 	*sort_four(stack_list **a, stack_list **b);
void 		sort_multi(stack_list **a, stack_list **b);
void 		find_max_min_b(stack_list **b, target_node *target);
void 		find_cheapest_move(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a, moves_node *inst_b, cheapest_node *cheapest);
void 		check_move_max_b(stack_list **b, moves_node *inst_b, target_node *target);
void 		check_move_min_b(stack_list **b, moves_node *inst_b, target_node *target);
void 		find_new_num(stack_list **b, int target_num, target_node *target, moves_node *inst_b);
void    	get_a(stack_list **a, moves_node *inst_a, int num, int c);
void 		check_move_min(stack_list **b);
int 		ft_is_sorted(stack_list **a);
void 		sort_stack_a(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a);
void 		move_max(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a);
void 		move_min(stack_list **a, stack_list **b, target_node *target, moves_node *inst_a);
void 		find_max_min_a(stack_list **a, target_node *target);
void    	find_new_num_a(stack_list **a, stack_list **b, int num, moves_node *inst_a);
void    	check_max_top(stack_list **a, stack_list **b, moves_node *inst_b, target_node *target);

#endif