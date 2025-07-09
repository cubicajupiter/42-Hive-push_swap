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
            if (is_unacceptable_char(argv[i][j]));
                return (ERROR);
            j++;
        }
        i++;
    }
    return (0);
}

int is_unacceptable_char(int c)
{
    if (c >= '0' && c <= '9' || c == '-' || c == ' ')
        return (0);
    return (ERROR);
}

void    ft_single_arg(char **arg, t_link **a)
{
    t_link	*new_node;

    new_node = ft_lstnew();
}

void    ft_multiple_args(char **arg, t_link **a)
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
