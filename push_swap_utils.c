/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:56:05 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/17 15:56:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_link	*ft_lstnew(char *argument)
{
	t_link		*new_node;
	int			data;

	data = ft_atoi(argument);
	new_node = malloc(sizeof(t_link));
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->previous = NULL;
	return (new_node);
}

void	ft_lstadd_back(t_link **head, t_link *new_node)
{
	t_link	*tmp;
	t_link	*previous_tmp;

	if (*head == NULL)
		*head = new_node;
	else
	{
		previous_tmp = NULL;
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_node;
		previous_tmp = tmp;
		tmp = tmp->next;
		tmp->previous = previous_tmp;
	}
}

void	ft_tail_to_head(t_link **head)
{
	t_link	*tmp;

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	(*head)->previous = tmp;
	tmp->next = *head;
}

void	ft_free_items(t_link **a)
{
	t_link	*tmp;

	(*a)->previous->next = NULL;
	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		tmp->previous = NULL;
		free(tmp);
	}
}

int	ft_atoi(char *nptr)
{
	int		sign;
	int		result;
	int		i;
	char	digit;

	i = 0;
	result = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9' && nptr[i] != '\0')
	{
		result *= 10;
		digit = nptr[i];
		result += digit - '0';
		i++;
	}
	return (result * sign);
}
