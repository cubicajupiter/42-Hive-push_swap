/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:20:02 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:29:09 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_link **dest_head, t_link **src_head)
{
    t_link	*tail;
    t_link	*old_top;
    t_link	*new_top;
    t_link	*swap_var;
// ft push will empty out data up to the last node. then *b will actually just continue to refer to the node that was the last one to be pushed from B to A, without setting its own *b to NULL.
    new_top = *src_head;
    swap_var = new_top->next;
    swap_var->previous = new_top->previous;
    swap_var->previous->next = swap_var;
    *src_head = swap_var;
    if (*dest_head)
    {
        old_top = *dest_head;
	tail = old_top->previous;
	tail->next = new_top;
	old_top->previous = new_top;
	new_top->previous = tail;
	new_top->next = old_top;
    }
    else
    {
	new_top->next = new_top;
	new_top->previous = new_top;
    }
    *dest_head = new_top;
}

void	pa(t_link **a, t_link **b)
{
    ft_push(a, b);
    write(1, "pa\n", 3);
}

void	pb(t_link **b, t_link **a)
{
    ft_push(b, a);
    //else
	//ft_init_push();
    write(1, "pb\n", 3);
}
