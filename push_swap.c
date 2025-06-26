/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:17:13 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:17:33 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main_unit(int argc, char **argv) //CHANGE NAME BACK TO MAIN() AFTER UNIT TESTING
{
	int				is_error;
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
	t_link	*new_node;

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
	if (argc <= 4)
		ft_bubble(a);
	else
	{
		while (1)
		{
			if (ft_is_sorted(a) && b)
				break ;
		//TURK SORT command conditions and calls here
		//RUN A COMMAND FUNCTION CALL
			write(1, "\n", 1);
		}
	}
}

void	ft_bubble(t_link **a)
{
	t_link			*tmp;
	int				top;
	int				below;

	tmp = *a;
	while (!ft_is_sorted(&tmp)) //INFINITE LOOP OF SA RA, reason below:
	{
		ra(&tmp); //currently there is one step missing. A bubble sort first compares first two values, swaps them if they're unsorted (SA), then increments by one (RA). After the last pair, it should start again from the first two. That's not done by this yet - it requires a third operation.
		top = tmp->content;
		below = tmp->next->content;
		if (top > below)
			sa(&tmp);
		//ra(&tmp);
	}
	*a = tmp;
}

int		ft_is_sorted(t_link **a)
{
	int				prev;
	int				current;
	t_link			*tmp;
	void			*first_address;

	prev = 0;
	tmp = *a;
	first_address = *a;
	prev = tmp->content;
	tmp = tmp->next;
	while (tmp && tmp != first_address)
	{
		current = tmp->content;
		if (current >= prev)
			prev = current;
		else
			return (NOT_SORTED);
		tmp = tmp->next;
	}
	return (SORTED);
}
