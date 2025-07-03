/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:38:04 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/30 17:11:02 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	ft_descend_in_b(t_link **b, t_link **a, int a_len)
{
	int		push_count;
	int		choice[7];

	push_count = 0;
	ft_initial_push(b, a, &push_count);
	while (a_len - push_count > 3)
	{
		choose_item(a, b, a_len - push_count, choice);
    //instructions and indexes are in choice[]
		pb(b, a);
		push_count++;
	}
}

void	ft_ascend_in_a(t_link **a, t_link **b)
{
	while ()
	{
// to the CLOSEST BIGGER -> bring closest bigger to TOP and then pb
// if theres no closest bigger, then node is the BIGGEST and its target the min value of A
// median: to rotate or reverse rotate. If target below median, revrot
	}
}

static void	choose_item(t_link **a, t_link **b, int a_len, int *choice)
{
	int		target_i;
	int		item_i;
  int   alt[7];

	item_i = 0;
  choice[COST] = INT_MAX;
	while (item_i < a_len)
	{
    alt[ITEM] = item_i;
    parameters_for_count(alt, a, b, a_len);
    ft_fetch_instructions(alt);
		ft_count_cost(alt);
		if (alt[COST] < choice[COST])
      choice = alt;
		item_i++;
	}
}

static void parameters_for_count(int *arr, t_link **a, t_link **b, int a_len)
{
  arr[TRGT] = ft_closest_smaller(arr[ITEM], a, b);
  arr[TRGT_TAIL_DIST] = ft_target_taildist(arr, b);
  arr[ITEM_TAIL_DIST] = a_len - arr[ITEM];
}
