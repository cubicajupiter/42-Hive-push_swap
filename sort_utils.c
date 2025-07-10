/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turksort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:32:40 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/10 09:08:46 by jvalkama         ###   ########.fr       */
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

int	ft_taildist(int target_i, t_link **cont)
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
    int     target_index;
    int     b_len;
    t_link  *tmp;

    target_index = ft_closest_smaller(arr[ITEM], a, b); 
    if (target_index == -1)
    {
        tmp = *b;
        b_len = ft_taildist(0, b);
        target_index = ft_fetch_index(&tmp, b_len, LARGEST);
    }
    arr[TRGT] = target_index;
    arr[TRGT_TAILDIST] = ft_taildist(arr[TRGT], b);
    arr[ITEM_TAILDIST] = a_len - arr[ITEM];
}
