/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:20:49 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:20:50 by jvalkama         ###   ########.fr       */
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

# define ERROR 1
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
# define RB 1
# define RRB 2
# define RA 3
# define RRA 4
# define RR 5
# define RRR 6

int					main_unit(int argc, char *argv[]); //CHANGE NAME AFTER UNIT TESTING
int			    	ft_link_items(t_link **a, int argc, char **argv);
void		    	ft_sort(int argc, t_link **a, t_link **b);
void		    	ft_bubble(t_link **a);
int			    	ft_is_sorted(t_link **a);
t_link				*ft_lstnew(char *argument);
void		    	ft_lstadd_back(t_link **cont_head, t_link *new_node);
void		    	ft_tail_to_head(t_link **cont_head);
void		    	free_items(t_link **cont_head);
static int			ft_atoi(char *nptr);
void			    ft_descend_in_b(t_link **b, t_link **a, int n);
void	    		ft_ascend_in_a(t_link **a, t_link **b);
static void			ft_choose_item(t_link **a, t_link **b, int a_len, int *choice);
void				ft_count_cost(int *arr);
void				ft_parameters_for_count(int *arr, t_link **a, t_link **b, int a_len);
int					ft_closest_smaller();
int					ft_target_taildist(int target_i, t_link **b);
void				ft_fetch_instructions(int *para, int *ops);
void				ft_update_concur_ops(int *ops, t_bool is_rev, int closer, int further);
int				    ft_initial_push(t_link **b, t_link **a, int a_len);
static void			ft_push(t_link **dest_cont, t_link **src_cont);
void			    pa(t_link **a, t_link **b);
void			    pb(t_link **b, t_link **a);
static void			ft_swap(t_link **cont);
void			    sa(t_link **a);
void			    sb(t_link **b);
void			    ss(t_link **a, t_link **b);
static void			ft_rotate(t_link **cont);
void			    ra(t_link **a);
void			    rb(t_link **b);
void			    rr(t_link **a, t_link **b);
static void			ft_rev_rotate(t_link **cont);
void			    rra(t_link **a);
void			    rrb(t_link **b);
void			    rrr(t_link **a, t_link **b);
void				ft_repeat_rotas(t_link **a, t_link **b, int *choice, t_bool is_Ascend_to_a);
void				ft_repeater(t_link **a, t_link **b, int command, int n);

#endif
