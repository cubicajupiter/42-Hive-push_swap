/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:24:14 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:28:01 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static  void	rev_rotate(t_link **cont)
{
	*cont = (*cont)->previous;
}

void	rra(t_link **a)
{
	rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_link **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_link **a, t_link **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
