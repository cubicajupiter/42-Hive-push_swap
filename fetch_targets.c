/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_targets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 09:49:34 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/07 10:34:01 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_fetch_a_item_value(t_link **a, int item_index)
{
    t_link	*tmp_a;
    int		a_value;

    tmp_a = *a;
    while (item_index > 0)
    {
        tmp_a = tmp_a->next;
        item_index--;
    }
    a_value = tmp_a->data;
    return (a_value);
}

int ft_closest_smaller(int item_index, t_link **a, t_link **b)
{
    int		a_value;
    int		closest_smaller;
    int		target_index;
    int		i;
    t_link	*tmp_b;

    i = 0;
    tmp_b = *b;
    a_value = ft_fetch_a_item_value(a, item_index);
    closest_smaller = INT_MIN;
    tmp_b->previous->next = NULL;
    while (tmp_b)
    {
        if (tmp_b->data < a_value && tmp_b->data > closest_smaller)
	{
            closest_smaller = tmp_b->data;
	    target_index = i;
	}
        tmp_b = tmp_b->next;
        i++;
    }
    (*b)->previous->next = *b;
    return (target_index);
}

void	ft_closest_larger(t_link **a, t_link **b, int *ops)
{
    t_link	*tmp_a;
    int		closest_larger;
    int		target_index;
    int		i;

    i = 0;
    closest_larger = INT_MAX;
    tmp_a = *a;
    tmp_a->previous->next = NULL;
    while (tmp_a)
    {
        if (tmp_a->data > (*b)->data && tmp_a->data < closest_larger)
        {
            closest_larger = tmp_a->data;
            target_index = i;
        }
        tmp_a = tmp_a->next;
        i++;
    }
    (*a)->previous->next = (*a);
    if (target_index <= i / 2)
	ops[RA] = target_index;
    else
	ops[RRA] = i - target_index;
}
