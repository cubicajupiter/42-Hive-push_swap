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

void    ft_descend_in_b(t_link **b, t_link **a, int initial_a_len)
{
    int   init_push_count;
    int   current_a_len;
    int   choice[7];

    init_push_count = ft_initial_push(b, a, initial_a_len);
    current_a_len = initial_a_len - init_push_count;
    while (current_a_len > 3)
    {
        ft_choose_item(a, b, current_a_len, choice);
        if (choice[COST] > 1)
            ft_repeat_rotas(a, b, choice, FALSE);
        pb(b, a);
        current_a_len--; //dont think it correctly rotates the largest on top each time
    }
}

void    ft_ascend_in_a(t_link **a, t_link **b, int b_len)
{
    int     ops[3];
    int     a_len;
    int     i;

    i = 0;
    while (i < b_len)
    {
        ops[0] = 0;
        ops[1] = 0;
        ops[2] = 0;
        ft_closest_larger(a, b, ops);
        if (ops[1] == -1)
        {
            a_len = ft_taildist(0, a);
            ft_bring_to_top(a, b, STACK_A, a_len);
        }
        else
            ft_repeat_rotas(a, b, ops, TRUE);
        if (i + 1 == b_len)
            pa(a, b, FINAL_PUSH);
        else
            pa(a, b, NOT_FINAL); //SOMETIMES A HEAD IS NOT ROTATED TO SMALLEST AT THE END, ESP WHEN NEGATIVES ARE INVOLVED, DEPENDING ON INITIALIZATION VALUES.
        i++;
    }
}

void    ft_choose_item(t_link **a, t_link **b, int a_len, int *choice)
{
    int   i;
    int   item_i;
    int   alt_params[4];
    int   alt_ops[7];

    item_i = 0;
    choice[COST] = INT_MAX;
    while (item_i < a_len && choice[COST] != 1)
    {
        alt_params[ITEM] = item_i;
        ft_parameters_for_count(alt_params, a, b, a_len);
        ft_fetch_instructions(alt_params, alt_ops);
        ft_count_cost(alt_ops);
        if (alt_ops[COST] < choice[COST])
        {
            i = 0;
            while (i < 7)
            {
                choice[i] = alt_ops[i];
                i++;
            }
        }
        item_i++;
    }
}

void    ft_fetch_instructions(int *para, int *ops)
{
    int     i;

    i = 0;
    while (i < 7)
    {
        ops[i] = 0;
        i++;
    }
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

void    ft_update_concur_ops(int *ops, t_bool is_rev, int closer, int further)
{
    if (is_rev)
        ops[RRR] = ops[closer]; //when closer and further are equal, will 
    else if (!is_rev)
        ops[RR] = ops[closer];
    ops[further] = ops[further] - ops[closer];
    ops[closer] = 0;
}
