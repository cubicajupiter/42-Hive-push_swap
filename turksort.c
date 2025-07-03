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
	//push first two A nodes to B, top and below(push only ONE to B if stack A has only 4 nodes)
	//first two become the FIRST target nodes, after which each addition becomes a new potential target node
	//then every node from A by reference to target nodes in B until 3 left in A.
	//target node in B is the CLOSEST SMALLER to the node of A
	//	if theres no closest smaller, then node is SMALLEST and its target the max value of B

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
  int   alt[8];

	item_i = 0;
	while (item_i < a_len)
	{
    alt[ITEM] = item_i;
    fill_parameters(alt, a, b, a_len);
		alt[COST] = count_cost(alt);
		if (alt[COST] < choice[COST])
		{
      choice[COST] = alt[COST];
      //all alt values become choice values
		}
		item_i++;
	}
}

static int	count_cost(int *alt)
{
	int		rota_count;
  
	if (target_i < target_rev_dist && item_i < item_rev_dist)
    //rotate both until smaller i is exhausted, then rotate other;
    rota_count = ;
	else if (target_rev_dist < target_i && item_rev_dist < item_i)
		//reverse rotate both til smaller i exhausted, then revrot other

	// count cost, save, compare to cost of next item, unless found a cost of 0.
  // cost is the minimum number of moves for the current pair.



	return (rota_count);
}


