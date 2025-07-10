/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:10:05 by jvalkama          #+#    #+#             */
/*   Updated: 2025/07/10 17:14:48 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_xerror_checks(int c_type, char *arg, int i) //ERROR CHECKS ALWAYS TRIGGERED NOW.......................
{
	if (i > 11)
		return (ERRNO);
	if (c_type == SIGN && !arg[i + 1])
		return (ERRNO);
	if (i - 1 >= 0)
	{
		if (c_type == SIGN)
			return (ft_sign_error(arg, i));
		if (arg[i] == '0')
			return (ft_null_error(arg, i));
	}
	return (0);
}

int	ft_sign_error(char *arg, int i)
{
	int		prev_c_type;

	prev_c_type = ft_is_acceptable_char(arg[i - 1]); 
	if (prev_c_type == DIGIT)
		return (ERRNO);
	else if (prev_c_type == SIGN)
		return (ERRNO);
	return (0);
}

int	ft_null_error(char *arg, int i)
{
	if (arg[i - 1] == '0')
		return (ERRNO);
	return (0);
}
