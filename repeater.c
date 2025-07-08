/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeater.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 15:33:18 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/04 17:04:03 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_repeat_rotas(t_link **a, t_link **b, int *ops, t_bool is_Ascend_to_a)
{
	int	command;

	command = 1;
	if (is_Ascend_to_a)
	{
		while (command <= 2)
		{
			if (ops[command])
				ft_repeater(a, b, command, ops[command]);
			command++;
		}
	}
	else
	{
		while (command < 7)
		{
			if (ops[command])
				ft_repeater(a, b, command, ops[command]);
			command++;
		}
	}
}

void	ft_repeater(t_link **a, t_link **b, int command, int n)
{
		if (command == RB)
			rb(b);
		else if (command == RA)
			ra(a);
		else if (command == RR)
			rr(a, b);
		else if (command == RRA)
			rra(a);
		else if (command == RRB)
			rrb(b);
		else if (command == RRR)
			rrr(a, b);
		if (n > 1)
			ft_repeater(a, b, command, n - 1);
}
