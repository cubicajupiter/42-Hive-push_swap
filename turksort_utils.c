/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:32:40 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/30 17:11:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_initial_push(t_link **b, t_link **a, int a_len)
{
    int push_count;

    push_count = 0;
    if (a_len > 4)
    {
        pb(b, a);
        push_count++;
    }
    pb(b, a);
    push_count++;
    return (push_count);
}

int	ft_target_taildist(int target_i, t_link **cont)
{
    int       dist;
    t_link    *tmp_cont;
  
    tmp_cont = (*cont)->next;
    dist = 1;
    while (tmp_cont && tmp_cont != *cont)
    {
        tmp_cont = tmp_cont->next;
        dist++;
    }
    dist = dist - target_i;
    return (dist);
}

void    ft_count_cost(int *alt_ops)
{
    int   cost;
    int   count;

    cost = 0;
    count = 1;
    while (count <= 6)
        cost += alt_ops[count++];
    alt_ops[COST] = cost + 1;
}

void    ft_parameters_for_count(int *arr, t_link **a, t_link **b, int a_len)
{
    arr[TRGT] = ft_closest_smaller(arr[ITEM], a, b);
    arr[TRGT_TAILDIST] = ft_target_taildist(arr[TRGT], b);
    arr[ITEM_TAILDIST] = a_len - arr[ITEM];
}
