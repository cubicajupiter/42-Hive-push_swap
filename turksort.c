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



void	ft_descend_in_b(t_link **b, t_link **a, int n)
{
	int		push_count;
	int		node_indexes[3];

	push_count = 0;
	ft_initial_push(b, a, &push_count);
	while (n - push_count > 3)
	{
		choose_item(a, b, n - push_count, node_indexes);
		if (choice_is_below_median(&node_indexes))
			revrotate_to_top();
		else
			rotate_to_top();
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
	int		total_cost;
	int		target_i;
	int		choice_i;

	choice_i = 0;
	choice[0] = INT_MAX;
	while (choice_i < a_len)
	{
		target_i = ft_closest_smaller(choice_i, a, b);
		total_cost = count_cost(choice_i, a_len, b, target_i);
		if (total_cost < choice[0])
		{
			choice[0] = total_cost;
			choice[1] = choice_i;
			choice[2] = target_i; //THESE THREE ARE THE ONLY INTELS REQUIRED FOR PERFORMING OPS IN CALLER
			// FURTHER INTEL IS ONLY REQUIRED IN COST COUNTING.
		}
		choice_i++;
	}
}

static int	count_cost(int choice_i, int a_len, t_link **b, int target_i) // RETURNS THE COST OF LOWEST COST PUSH
{
	int		target_distance;
	int		choice_distance;
	int		rota_count; //rota count approximates to a concept of total count of rotations, but curently has no logic for revrot/rot aspect which will happen by the negatives&positives of target and choice distances, somehow, once implemented

	
	if (dist_to_top < dist_to_bottom)
		rota_count = count_dist_to_top;
	else
		rota_count = count_dist_to_bottom;
	// so you gotta count the nodes' distance to top for A and B - both for A and B in total. make max use of RR
	// count cost, save, compare to cost of next item, unless found a cost of 0.

	return (count);
}

static int	count_distance()
{
	//return negative or positive integer signifying the target's distance to top and bottom, return positive if closer to top, negative if closer to bottom.
	int		i;
	t_link	*tmp_b;

	i = 1;
	tmp_b = (*b)->next;
	while (tmp_b != *b)
		i++;
}
