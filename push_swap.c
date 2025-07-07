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

int	main_unit(int argc, char **argv) //CHANGE NAME BACK TO MAIN() AFTER UNIT TESTING
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
			return (ERROR);
		ft_sort(argc, &a, &b);
		ft_free_items(&a);
	}
	return (0);
}

int		ft_link_items(t_link **a, int argc, char **argv)
{
	int			i;
	t_link		*new_node;

	i = 1;
	while (i < argc)
	{
		new_node = ft_lstnew(argv[i]);
		if (!new_node) //THE ONLY ERROR CHECK SO FAR...
		{
			ft_free_items(a);
			return (ERROR);
		}
		ft_lstadd_back(a, new_node);
		i++;
	}
	ft_tail_to_head(a);
	return (0);
}

void	ft_sort(int argc, t_link **a, t_link **b)
{
	int		item_count;

	item_count = argc - 1;
	if (item_count <= 3)
		ft_bubble(a);
	else
	{
		ft_descend_in_b(b, a, item_count);
		ft_bubble(a);
		ft_largest_to_top(a, b); //so I guess I should put largest to top in both before beginning ascent. Also ft_push needs a way to nullify a cont once it empties.
		ft_ascend_in_a(a, b);
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
