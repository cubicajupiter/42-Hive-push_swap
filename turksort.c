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



void	ft_descend_in_b(t_link **b, t_link **a, int initial_a_len)
{
	int	init_push_count;
	int	current_a_len;
	int	choice[7];

	init_push_count = ft_initial_push(b, a, initial_a_len);
	current_a_len = initial_a_len - init_push_count;
	while (current_a_len > 3)
	{
		ft_choose_item(a, b, current_a_len, choice);
		ft_repeat_rotas(a, b, choice, FALSE);
		pb(b, a);
		current_a_len--;
	}
}

void	ft_ascend_in_a(t_link **a, t_link **b)
{
	int		ops[3];
	int		nextlarger;
	int		target_index;
	int		i;
	t_link		*tmp_a;

	if (ft_is_sorted(a))
		return ;
	i = 0;
	nextlarger = 0;
	tmp_a = *a;
	tmp_a->previous->next = NULL;
	while (tmp_a) //ALL THIS SHIT WONT FIT IN ONE FUNC AND WOULD BE MOR ELEGANT IF MULTIPLE FUNCS
	{
		if (tmp_a->data > (*b)->data && tmp_a->data < nextlarger)
		{
			nextlarger = tmp_a->data;
			target_index = i;
		}
		tmp_a = tmp_a->next;
		i++;
	}
	(*a)->previous->next = (*a);
	//pass to ft_repeater(a, b, rot or revrot, times=cost)
	ft_repeat_rotas(a, b, ops, TRUE);
	pa(a, b);
	ft_ascend_in_a(a, b);
}

static void	ft_choose_item(t_link **a, t_link **b, int a_len, int *choice)
{
	int	i;
	int	item_i;
	int	alt_params[4];
	int	alt_choice[7];

	item_i = 0;
	choice[COST] = INT_MAX;
	while (item_i < a_len)
	{
		i = 0;
		alt_params[ITEM] = item_i;
		ft_parameters_for_count(alt_params, a, b, a_len);
		ft_fetch_instructions(alt_params, alt_choice);
		ft_count_cost(alt_choice);
		if (alt_choice[COST] < choice[COST])
		{
			while (i < 7)
			{
				choice[i] = alt_choice[i];
				i++;
			}
		}
		item_i++;
	}
}

void	ft_fetch_instructions(int *para, int *ops)
{
	if (para[ITEM] <= para[ITEM_TAILDIST])
		ops[RA] = para[ITEM];
	else if (para[ITEM] > para[ITEM_TAILDIST])
		ops[RRA] = para[ITEM_TAILDIST];
	if (para[TRGT] <= para[TRGT_TAILDIST])
		ops[RB] = para[TRGT];
	else if (para[TRGT] > para[TRGT_TAILDIST])
		ops[RRB] = para[TRGT_TAILDIST];
	if (ops[RA] && ops[RB] && ops[RA] <= ops[RB])
		ft_update_concur_ops(ops, NOT_REV, RA, RB);
	else if (ops[RA] && ops[RB] && ops[RA] > ops[RB])
		ft_update_concur_ops(ops, NOT_REV, RB, RA);
	else if (ops[RRA] && ops[RRB] && ops[RRA] <= ops[RRB])
		ft_update_concur_ops(ops, IS_REV, RRA, RRB);
	else if (ops[RRA] && ops[RRB] && ops[RRA] > ops[RRB])
		ft_update_concur_ops(ops, IS_REV, RRB, RRA);
}

void	ft_update_concur_ops(int *ops, t_bool is_rev, int closer, int further)
{
	if (is_rev)
		ops[RRR] = ops[closer]; //when closer and further are equal, will 
	else if (!is_rev)
		ops[RR] = ops[closer];
	ops[further] = ops[further] - ops[closer];
	ops[closer] = 0;
}
