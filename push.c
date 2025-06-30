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

static void	push(t_link **dest_cont, t_link **src_cont)
{
	t_link		*tail;
	t_link		*old_top;
	t_link		*new_top;
	t_link		*swap_var;

	old_top = *dest_cont;
	new_top = *src_cont;
	tail = old_top->previous;
	swap_var = new_top->next->previous;
	new_top->next->previous = new_top->previous;
	new_top->previous->next = swap_var;
	tail->next = new_top;
	old_top->previous = new_top;
	new_top->previous = tail;
	new_top->next = old_top;
}

void	pa(t_link **a, t_link **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_link **b, t_link **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
