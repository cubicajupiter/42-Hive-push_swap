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
    pb(b, a); //initial push to B fails now, cuz push() presupposes existing nodes in dest cont for link
    ft_tail_to_head(b);
    push_count++;
    return (push_count);
}

int ft_closest_smaller(int item_index, t_link **a, t_link **b)
{
    int       a_value;
    int       closest_smaller;
    t_link    *tmp_a;
    t_link    *tmp_b;
    int       i;

    i = 0;
    tmp_a = *a;
    tmp_b = *b;
    closest_smaller = 0;
    while (item_index > 0)
    {
        tmp_a = tmp_a->next;
        item_index--;
    }
    a_value = tmp_a->data;
    tmp_b->previous->next = NULL;
    while (tmp_b)
    {
        if (tmp_b->data < a_value && tmp_b->data > closest_smaller)
            closest_smaller = tmp_b->data;
        tmp_b = tmp_b->next;
        i++; //SOMETHING MISSING: will always return index of last element.
    }
    (*b)->previous->next = *b;
}

void	ft_closest_larger(t_link **a, t_link **b, int *ops)
{
	t_link	tmp_a;
	int		closest_larger;
	int		target_index;
	int		i;

	i = 0;
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
	if (target_index < i / 2)
		ops[RA] = target_index;
	else
		ops[RRA] = i - target_index;
}

int	ft_target_taildist(int target_i, t_link **cont)
{
    int       dist;
    t_link    *tmp_cont;
  
    tmp_cont = (*cont)->next;
    dist = 1;
    while (tmp_cont && tmp_cont != *cont) //THERES NOTHING LINKING CIRCULARILY B NODES YET
    {
        tmp_cont = tmp_cont->next;
        dist++;
    }
    dist = dist - target_i;
    return (dist);
}

void    ft_count_cost(int *alt_ops) //sum up operations noted on the alt
{
    int   cost;
    int   count;

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
