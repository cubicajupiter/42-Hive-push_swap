/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:12:04 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/10 16:54:11 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_preprocess_arguments(int argc, char **argv)
{
    int		i;
    int		j;
	int		c_type;

    i = 1;
    while (i < argc)
    {
        j = 0;
		if (!argv[i][j])
			return (ERRNO);
        while (argv[i][j])
        {
			c_type = ft_is_acceptable_char(argv[i][j]);
			if (c_type == ERRNO)
				return (ERRNO);
			if (ft_xerror_checks(c_type, argv[i], j))
				return (ERRNO);
			j++;
		}
		i++;
	}
    return (0);
}

int	ft_is_acceptable_char(int c)
{
	if (c >= '0' && c <= '9')
		return (DIGIT);
	else if (c == '-')
		return (SIGN);
	else if (c == ' ')
		return (SPACE);
	else if (c == '\0')
		return (NULLTER);
	return (ERRNO);
}

int	ft_parse_arg_str(char *arg, t_link **a)
{
	char	buffer[12];
	int		ret_no;
	int		node_count;
	int		is_error;
	int		j;

	j = 0;
	node_count = 0;
	ret_no = 0;
	while (ret_no != NULLTER)
	{
		ret_no = ft_is_acceptable_char(*arg);
		if (ret_no == DIGIT || ret_no == SIGN)
			buffer[j++] = *arg;
		else if (ret_no == SPACE || ret_no == NULLTER)
		{
			buffer[j] = '\0';
			is_error = ft_arg_to_node(buffer, a);
			node_count++;
			if (is_error == ERRNO)
				return (ERRNO);
			j = 0;
		}
		arg++;
	}
	return (node_count);
}

int		ft_arg_to_node(char *arg, t_link **a)
{
	t_link		*new_node;

    new_node = ft_lstnew(arg);
    if (!new_node)
    {
		ft_free_items(a);
		return (ERRNO);
    }
    ft_lstadd_back(a, new_node);
	return (SUCCESS);
}

int		ft_check_duplicates(t_link **a, int item_count)
{
	int			number;
	t_link		*tmp;
	t_link		*tmp_cmp;
	int			i;
	int			j;

	tmp = *a;
	i = 0;
	while (i < item_count)
	{
		j = 1;
		number = tmp->data;
		tmp_cmp = tmp;
		while (i + j < item_count)
		{
			tmp_cmp = tmp_cmp->next;
			if (tmp_cmp->data == number)
				return (ERRNO);
			j++;
		}
		tmp = tmp->next; 
		i++;
	}
	return (item_count);
}
