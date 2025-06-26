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

typedef struct s_stack_item
{
	int						content;
	struct s_stack_item		*next;
	struct s_stack_item		*previous;
}	t_link;

# define ERROR 1
# define FALSE 0
# define SORTED 1
# define NOT_SORTED 0

int				main_unit(int argc, char *argv[]); //CHANGE NAME AFTER UNIT TESTING
int				ft_link_items(t_link **a, int argc, char **argv);
void			ft_sort(int argc, t_link **a, t_link **b);
void			ft_bubble(t_link **a);
int				ft_is_sorted(t_link **a);
t_link			*ft_lstnew(char *argument);
void			ft_lstadd_back(t_link **cont_head, t_link *new_node);
void			ft_tail_to_head(t_link **cont_head);
void			ft_free_items(t_link **cont_head);
int				ft_atoi(char *nptr);
void			ft_push(t_link **dest_cont, t_link **src_cont);
void			pa(t_link **a, t_link **b);
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

#endif
