/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:17:13 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/10 16:47:15 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	int			item_count;
	t_link		*a;
	t_link		*b;

	item_count = 0;
	if (argc > 1)
	{
		a = NULL;
		b = NULL;
		item_count = ft_link_items(&a, argc, argv);
		item_count = ft_check_duplicates(&a, item_count);
		if (item_count == ERRNO)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		
		ft_sort(item_count, &a, &b);
		ft_free_items(&a);
	}
	return (0);
}

int		ft_link_items(t_link **a, int argc, char **argv)
{
	int			i;
	int			ret_no;
	int			item_count;

	i = 1;
	item_count = 0;
	ret_no = ft_preprocess_arguments(argc, argv);
	if (ret_no == ERRNO)
		return (ERRNO);
	if (argc == 2)
	{
		ret_no = ft_parse_arg_str(argv[i++], a);
		if (ret_no == ERRNO)
			return (ERRNO);
		item_count = ret_no;
	}
	while (i < argc)
	{
		ret_no = ft_arg_to_node(argv[i++], a);
		if (ret_no == ERRNO)
			return (ERRNO);
		item_count++;
	}
	ft_tail_to_head(a);
	return (item_count);
}

void	ft_sort(int item_count, t_link **a, t_link **b)
{
	int		b_len;

	if (item_count <= 3)
		ft_bubble(a);
	else if (!ft_is_sorted(a))
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
