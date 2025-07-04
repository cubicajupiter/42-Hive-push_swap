/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:19:56 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:28:18 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_link **cont)
{
	*cont = (*cont)->next;
}

void	ra(t_link **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_link **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_link **a, t_link **b)
{
	rotate(a);	
	rotate(b);
	write(1, "rr\n", 3);
}
