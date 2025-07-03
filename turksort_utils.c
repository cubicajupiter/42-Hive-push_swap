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
	pb(b, a); //initial push to B fails now, cuz push() presupposes existing nodes in dest cont for linking
  ft_tail_to_head(b);
	*push_count++;
}

int		ft_closest_smaller(int choice_i, t_link **a, t_link **b)
{
  int     value;
  int     closest_smaller;
  t_link  *tmp_a;
  t_link  *tmp_b;
  int     i;

  i = 0;
  tmp_a = *a;
  tmp_b = *b;
  closest_smaller = 0;
  while (choice_i > 0)
  {
    tmp_a = tmp_a->next;
    choice_i--;
  }
  value = tmp_a->content;
  tmp_b->previous->next = NULL;
  while (tmp_b)
  {
    if (tmp_b->content < value && tmp_b->content > closest_smaller) //caveat: unoptimized in respect of placement of closest_smaller.
      closest_smaller = tmp_b->content; //OPTIMIZED WOULD CHOOSE THE ONE CLOSER TO THE TOP GIVEN TWO SAME CLOSEST SMALLER INTS, but that would require more lines than I have.
    tmp_b = tmp_b->next;
    i++;
  }
  (*b)->previous->next = *b;
}

//int		closest_larger() CLOSEST_LARGER IMPLEMENT IN FT_ASCEND_A ?
//{
//
//}

void ft_fetch_instructions(int *array)
{
  if (array[ITEM] <= array[ITEM_TAIL_DIST] && array[TRGT] <= array[TRGT_TAIL_DIST])
    if (array[ITEM] <= array[TRGT])
      //ROTATE BOTH xITEM TIMES, THEN ROTATE ONLY TRGT REMAININIG xTARGET TIMES
      ;
    else
      //ROTATE BOTH xTARGET TIMES, THEN ROTATE ONLY ITEM REMAINING xITEM TIMES
      ;
  if (array[ITEM] > array[ITEM_TAIL_DIST] && array[TRGT] > array[TRGT_TAIL_DIST])
    if (array[ITEM_TAIL_DIST] <= array[TRGT_TAIL_DIST])
      //ROTATE BOTH xITEM_TAIL_DIST TIMES, THEN ROTATE ONLY TRGT REMAINING xTARGET_TAIL_DIST TIMES
      ;
    else
      //ROTATE BOTH xTARGET_TAIL_DIST TIMES, THEN ROTATE ONLY ITEM REMAINING xITEM_TAIL_DIST TIMES
      ;
  //IF after concurrent Rs the distance of remaining side is closer to top than it would have been without concurrent Rs
  // then should be RRd even though the other was closer to tail. So if e.g.:
  // target_i is at 3/4 up the stack and item_i is 2/4 up the stack, 2xRR will leave only 1R for target. These "edge cases" need to be implemented
}

int  ft_target_taildist(int target_i, t_link **b) //RETURNS DISTANCE TO BOTTOM ONLY
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

void  ft_count_cost(int *arr)
{
  int cost;
  int count;

  count = 1;
  while (count <= 6)
    cost += arr[count++];
  arr[COST] = cost + 1;
}
