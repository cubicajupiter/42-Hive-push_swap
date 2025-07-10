/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:20:49 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/10 17:14:46 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack_item
{
	int						data;
	struct s_stack_item		*next;
	struct s_stack_item		*previous;
}	t_link;

typedef enum
{
	FALSE,
	TRUE
}	t_bool;

# define DIGIT 1
# define SIGN 2
# define SPACE 3
# define NULLTER 4
# define NOT_FINAL 0
# define FINAL_PUSH 1
# define STACK_A 0
# define STACK_B 2
# define SMALLEST 0
# define LARGEST 2
# define ERRNO -1
# define SUCCESS 1
# define FALSE 0
# define SORTED 1
# define NOT_SORTED 0
# define NOT_REV 0
# define IS_REV 1
# define TRGT 0
# define TRGT_TAILDIST 1
# define ITEM 2
# define ITEM_TAILDIST 3
# define COST 0
# define RA 1
# define RRA 2
# define RB 3
# define RRB 4
# define RR 5
# define RRR 6

int				main(int argc, char *argv[]);
int				ft_link_items(t_link **a, int argc, char **argv);
void			ft_sort(int argc, t_link **a, t_link **b);
void			ft_bubble(t_link **a);
int				ft_is_sorted(t_link **a);
int				ft_preprocess_arguments(int argc, char **argv);
int				ft_is_acceptable_char(int c);
int				ft_parse_arg_str(char *arg, t_link **a);
int				ft_arg_to_node(char *arg, t_link **a);
int				ft_check_duplicates(t_link **a, int item_count);
int				ft_xerror_checks(int c_type, char *arg, int i);
int				ft_sign_error(char *arg, int i);
int				ft_null_error(char *arg, int i);
t_link			*ft_lstnew(char *argument);
void			ft_lstadd_back(t_link **cont_head, t_link *new_node);
void			ft_tail_to_head(t_link **cont_head);
void			ft_free_items(t_link **cont_head);
long long		ft_atoi(char *nptr);
void			ft_descend_in_b(t_link **b, t_link **a, int n);
void			ft_ascend_in_a(t_link **a, t_link **b, int stack_len);
void			ft_choose_item(t_link **a, t_link **b, int a_len, int *choice);
void			ft_count_cost(int *arr);
void			ft_parameters_for_count(int *arr, t_link **a, t_link **b, int a_len);
void			ft_bring_to_top(t_link **a, t_link **b, int n_stack, int stack_len);
int				ft_fetch_index(t_link **tmp, int stack_len, int index_of);
int				ft_closest_smaller(int item_index, t_link **a, t_link **b);
void			ft_closest_larger(t_link **a, t_link **b, int *ops);
int				ft_fetch_a_item_value(t_link **a, int item_index);
int				ft_taildist(int target_i, t_link **b);
void			ft_fetch_instructions(int *para, int *ops);
void			ft_update_concur_ops(int *ops, t_bool is_rev, int closer, int further);
int				ft_initial_push(t_link **b, t_link **a, int a_len);
void			ft_push(t_link **dest_cont, t_link **src_cont);
void			pa(t_link **a, t_link **b, t_bool is_final_push);
void			pb(t_link **b, t_link **a);
void			ft_swap(t_link **cont);
void			sa(t_link **a);
void			sb(t_link **b);
void			ss(t_link **a, t_link **b);
void			ft_rotate(t_link **cont);
void			ra(t_link **a);
void			rb(t_link **b);
void			rr(t_link **a, t_link **b);
void			ft_rev_rotate(t_link **cont);
void			rra(t_link **a);
void			rrb(t_link **b);
void			rrr(t_link **a, t_link **b);
void			ft_repeat_rotas(t_link **a, t_link **b, int *choice, t_bool is_Ascend_to_a);
void			ft_repeater(t_link **a, t_link **b, int command, int n);

#endif
