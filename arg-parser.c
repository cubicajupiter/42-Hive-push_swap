/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:12:04 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/09 13:58:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

int ft_preprocess_arguments(int argc, char **argv)
{
    int     i;
    int     j;

    i = 1;
    while (i < argc)
    {
        j = 0;
        while (argv[i][j])
        {
            if (is_acceptable_char(argv[i][j]));
                j++;
			else
				return (ERROR);
        }
        i++;
    }
    return (0);
}

int is_acceptable_char(int c)
{
    if(c >= '0' && c <= '9' || c == '-')
		return(1);
	else if (c == ' ');
		return (2);
	return (ERROR);
}

void    ft_parse_arg_str(char **arg, t_link **a)
{
	char	buffer[12];
	int		c_type;
	int		i;
	int		j;

	while (arg[i])
	{
		c_type = is_acceptable_char(arg[i]);
		if (c_type == 1)
		{
			buffer[j] = arg[i];
			j++;
		}
		else if (c_type == 2)
		{
			buffer[j] = '\0';
			ft_arg_to_node(buffer, a);
			j = 0;
		}
		i++;
	}
}

void    ft_arg_to_node(char *arg, t_link **a)
{
    t_link	*new_node;

    new_node = ft_lstnew(arg);
    if (!new_node)
    {
		ft_free_items(a);
		return (ERROR);
    }
    ft_lstadd_back(a, new_node);
    i++;
}
