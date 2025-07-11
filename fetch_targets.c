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
    target_index = -1;
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
    target_index = NONE_LARGER;
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

void    ft_bring_to_top(t_link **a, t_link **b, int n_stack, int stack_len)
{
    int     target_index;
    t_link  *tmp;

    if (n_stack == STACK_B)
        tmp = *b;
    else if (n_stack == STACK_A)
        tmp = *a;
    target_index = ft_fetch_index(&tmp, stack_len, n_stack);
    if (target_index > 0 && target_index <= stack_len / 2)
        ft_repeater(a, b, RA + n_stack, target_index);
    else if (target_index > 0)
        ft_repeater(a, b, RRA + n_stack, stack_len - target_index);
}

int    ft_fetch_index(t_link **tmp, int stack_len, int index_of)
{
    int     largest_sofar;
    int     smallest_sofar;
    int     target_index;
    int     i;

    i = 0;
    target_index = 0;
    largest_sofar = INT_MIN;
    smallest_sofar = INT_MAX;
    while (i < stack_len)
    {
        if (index_of == LARGEST && (*tmp)->data > largest_sofar)
        {
            largest_sofar = (*tmp)->data;
            target_index = i;
        }
        else if (index_of == SMALLEST && (*tmp)->data < smallest_sofar)
        {
            smallest_sofar = (*tmp)->data;
            target_index = i;
        }
        *tmp = (*tmp)->next;
        i++;
    }
    return (target_index);
}
