/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:17:13 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/07 11:17:48 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int			is_error;
	t_link		*a;
	t_link		*b;

	is_error = FALSE;
	if (argc > 1) //WHAT IF YOU PASS LETTERS INSTEAD OF DIGITS AS ARG?
	{
		a = NULL;
		b = NULL;
		is_error = ft_link_items(&a, argc, argv);
		if (is_error)
			write (1, "Error", 5);
		ft_sort(argc, &a, &b);
		ft_free_items(&a);
	}
	return (0);
}

int		ft_link_items(t_link **a, int argc, char **argv)
{
	int			i;
	int			is_error;

	i = 1;
	is_error = ft_preprocess_arguments(argc, argv);
	if (is_error)
		return (ERROR);
	if (argc == 2)
	{
		ft_single_arg(argv[i], a);
		i++;
	}
	while (i < argc)
	{
		ft_multiple_args(argv[i], a);
		i++;
	}
	ft_tail_to_head(a);
	return (0);
}

void	ft_sort(int argc, t_link **a, t_link **b)
{
	int		item_count;
	int		b_len;

	item_count = argc - 1;
	if (item_count <= 3)
		ft_bubble(a);
	else
	{
		ft_descend_in_b(b, a, item_count);
		ft_bubble(a);
		b_len = ft_taildist(0, b);
		ft_bring_to_top(a, b, STACK_B, b_len);
		ft_ascend_in_a(a, b, b_len);
	}
}

void	ft_bubble(t_link **a)
{
	t_link		*tmp;
	int			top;
	int			below;
	int			i;

	i = 0;
	tmp = *a;
	while (!ft_is_sorted(&tmp))
	{
		top = tmp->data;
		below = tmp->next->data;
		if (top > below)
			sa(&tmp);
		if (!ft_is_sorted(&tmp))
		{
			if (i % 2 == 1)
				rra(&tmp);
			else
				ra(&tmp);
		}
		i++;
	}
	*a = tmp;
}

int		ft_is_sorted(t_link **a)
{
	int			prev;
	int			current;
	t_link		*tmp;
	void		*first_address;

	prev = 0;
	tmp = *a;
	first_address = *a;
	prev = tmp->data;
	tmp = tmp->next;
	while (tmp && tmp != first_address)
	{
		current = tmp->data;
		if (current >= prev)
			prev = current;
		else
			return (NOT_SORTED);
		tmp = tmp->next;
	}
	return (SORTED);
}
