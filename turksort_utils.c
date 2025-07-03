/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:32:40 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/30 17:11:07 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_initial_push(t_link **b, t_link **a, int *push_count);
{
	if (n > 4)
	{
		pb(b, a);
		*push_count++;
	}
	pb(b, a);
	*push_count++;
}

static int		ft_closest_smaller(int choice_i, t_link **a, t_link **b)
{

}

//int		closest_larger() CLOSEST_LARGER IMPLEMENT IN FT_ASCEND_A ?
//{
//
//}

static void  fetch_instructions(int choice)
{
  
}

static int	ft_target_dist(int target_i, t_link **b) //RETS DISTANCE TO BOTTOM ONLY
{
	int		  dist;
	t_link	*tmp_b;
	
	tmp_b = (*b)->next;
  dist = 1;
	while (tmp_b && tmp_b != *b) //THERES NOTHING LINKING B NODES YET
  {
    tmp_b = tmp_b->next;
		dist++;
  }
  dist = dist - target_i;
  return (dist);
}

void  fill_parameters(int *array, t_link *a, t_link *b, int a_len)
{
    array[TARGET] = ft_closest_smaller(array[ITEM], a, b);
    array[TARGET_TAIL_DIST] = ft_target_dist(array, b);
    array[ITEM_TAIL_DIST] = a_len - array[ITEM];
    array[NULLTER] = NULL;
    fetch_instructions(array);
}
