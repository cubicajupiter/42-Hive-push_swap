/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:19:49 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:28:31 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_link	**cont)
{
	t_link		*first;
	t_link		*second;
	t_link		*third;
	t_link		*tail;

	first = *cont;
	second = first->next;
	third = second->next;
	tail = first->previous;
	tail->next = second;
	third->previous = first;
	first->next = third;
	first->previous = second;
	second->next = first;
	second->previous = tail;
	*cont = second;
}

void	sa(t_link **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_link **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_link **a, t_link **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
