/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_testing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvalkama <jvalkama@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:23:40 by jvalkama          #+#    #+#             */
/*   Updated: 2025/06/25 11:24:03 by jvalkama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	test_primaries();
int	test_utils();
int	test_swap();
int	test_push();
int	test_rotate();
int	test_revrotate();

int main(void)
{
	int	result_p;
	int	result_u;
	int	result_s;
	int	result_pu;
	int	result_r;
	int	result_rr;

	printf("Begin unit tests.\n");
	printf("\n\n");

	printf("PRIMARY FUNCTIONS:\n\n");
	result_p = test_primaries();
	printf("\n\n");

	printf("UTIL FUNCTIONS:\n\n");
	result_u = test_utils();
	printf("\n\n");

	printf("SWAP FUNCTONS:\n\n");
	result_s = test_swap();
	printf("\n\n");

	printf("PUSH FUNCTIONS:\n\n");
	result_pu = test_push();
	printf("\n\n");

	printf("ROTATION FUNCTIONS:\n\n");
	result_r = test_rotate();
	printf("\n\n");

	printf("REVERSE ROTATION FUNCTIONS:\n\n");
	result_rr = test_revrotate();
	printf("\n");

	return 0;
}

void	initialize_test_parameters(t_link **a, char **args, int argc)
{
	ft_link_items(a, argc, args); //valgrind error.
}

void	loop_and_print_values(t_link **cont)
{
	t_link	*tmp;

	if (*cont == NULL)
		return ;
	tmp = *cont;
	printf("%d ", tmp->data);
	tmp = tmp->next;
	while (tmp != *cont)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n\n");
}

int	test_primaries()
{
	char	*edgeargs[9] = {"name", "1000", "0", "69", "-69", "11", "99", "21", "-9"};
	char	*edgeargs2[9] = {"name", "1", "2", "69", "0", "-69", "11", "21", "-9"};
	char	*argumentsover3[10] = {"name", "30", "1", "4", "42", "17", "7", "9", "2", "57"};
	char	*arguments3[4] = {"name", "8", "2", "5"};
	char	*args23[24] = {"name", "30", "1", "4", "-69", "42", "17", "7", "9", "2", "57", "3", "100", "68", "80", "1000", "0", "69", "311", "11", "24", "99", "21", "-9"};
	t_link	*a8 = NULL;
	t_link	*b8 = NULL;
	t_link	*edgea2 = NULL;
	t_link	*edgeb2 = NULL;
	t_link	*a9 = NULL;
	t_link	*a3 = NULL;
	t_link	*b9 = NULL;
	t_link	*b3 = NULL;
	t_link	*a23 = NULL;
	t_link	*b23 = NULL;

	initialize_test_parameters(&a8, edgeargs, 9);
	initialize_test_parameters(&edgea2, edgeargs2, 9);
	initialize_test_parameters(&a9, argumentsover3, 10);
	initialize_test_parameters(&a3, arguments3, 4);
	initialize_test_parameters(&a23, args23, 24);

	printf("-TESTING PRIMARY SORT FUNCTION-\n");
	printf("Edge Arg Values before sort:\n");
	loop_and_print_values(&a8);
	ft_sort(9, &a8, &b8);
	printf("Edge Arg Values after sort:\n");
	loop_and_print_values(&a8);
	printf("\n");

	printf("Edge Arg Values !!SET 2!! before sort:\n");
	loop_and_print_values(&edgea2);
	ft_sort(9, &edgea2, &edgeb2);
	printf("Edge Arg Values !!SET 2!! after sort:\n");
	loop_and_print_values(&edgea2);
	printf("\n");

	printf("A9 Values before sort:\n");
	loop_and_print_values(&a9);
	ft_sort(10, &a9, &b9);
	printf("A9 Values after sort:\n");
	loop_and_print_values(&a9);
	printf("B9 Values after sort:\n");
	loop_and_print_values(&b9);
	printf("\n");

	printf("A3 Values before sort:\n");
	loop_and_print_values(&a3);
	ft_sort(4, &a3, &b3);
	printf("A3 Values after sort:\n");
	loop_and_print_values(&a3);
	printf("\n");

	printf("A23 Values before sort:\n");
	loop_and_print_values(&a23);
	ft_sort(24, &a23, &b23);
	printf("A23 Values after sort:\n");
	loop_and_print_values(&a23);
	printf("\n");

	ft_free_items(&a9);
	ft_free_items(&edgea2);
	ft_free_items(&a3);
	ft_free_items(&a23);

	char	*bubble_args[4] = {"name", "8", "2", "5"};
	char	*bubble_args2[4] = {"name", "42", "16", "1"};
	char	*bubble_args3[4] = {"name", "50", "99", "5"};
	t_link	*a_bubble = NULL;
	t_link	*a_bubble2 = NULL;
	t_link	*a_bubble3 = NULL;
	int		res;

	initialize_test_parameters(&a_bubble, bubble_args, 4);
	initialize_test_parameters(&a_bubble2, bubble_args2, 4);
	initialize_test_parameters(&a_bubble3, bubble_args3, 4);

	printf("Testing [ ft_bubble ]\n");
	printf("-CHECKING WHETHER BUBBLE SORT WORKS-\n");

	printf("	Stack 1 before bubble sort:\n"); // SET 1
	res = ft_is_sorted(&a_bubble);
	printf("		0 if unsorted: %d\n", res);
	ft_bubble(&a_bubble);
	printf("	Stack 1 after bubble sort:\n");
	res = ft_is_sorted(&a_bubble);
	printf("		1 if sorted: %d\n\n", res);

	printf("	Stack 2 before bubble sort:\n"); // SET 2
	res = ft_is_sorted(&a_bubble2);
	printf("		0 if unsorted: %d\n", res);
	ft_bubble(&a_bubble2);
	printf("	Stack 2 after bubble sort:\n");
	res = ft_is_sorted(&a_bubble2);
	printf("		1 if sorted: %d\n\n", res);

	printf("	Stack 3 before bubble sort:\n"); // SET 3
	res = ft_is_sorted(&a_bubble3);
	printf("		0 if unsorted: %d\n", res);
	ft_bubble(&a_bubble3);
	printf("	Stack 3 after bubble sort:\n");
	res = ft_is_sorted(&a_bubble3);
	printf("		1 if sorted: %d\n\n\n", res);

	ft_free_items(&a_bubble);	
	ft_free_items(&a_bubble2);	
	ft_free_items(&a_bubble3);	


	char		*sorted_args[10] = {"name", "1", "2", "4", "7", "9", "15", "28", "42", "57"};
	char		*unsorted_args[10] = {"name", "30", "1", "4", "42", "17", "7", "9", "2", "57"};
	t_link		*a_sorted = NULL;
	t_link		*a_unsorted = NULL;
	int			sorted_res;
	int			unsorted_res;

	initialize_test_parameters(&a_sorted, sorted_args, 10);
	initialize_test_parameters(&a_unsorted, unsorted_args, 10);
	printf("Testing [ ft_is_sorted ]\n");
	printf("-CHECKING IF STACK IS SORTED-\n");
	printf("	Sorted:\n");
	sorted_res = ft_is_sorted(&a_sorted);
	printf("		1 if sorted: %d\n", sorted_res);
	printf("	Unsorted:\n");
	unsorted_res = ft_is_sorted(&a_unsorted);
	printf("		0 if unsorted: %d\n\n", unsorted_res);
	ft_free_items(&a_sorted);
	ft_free_items(&a_unsorted);
	return 0;
}

int	test_utils()
{
	int			i = 0;
	t_link		*a = NULL;
	t_link		*tmp = NULL;
	char		*argumentsover3[10] = {"name", "30", "1", "4", "42", "17", "7", "9", "2", "57"};

	printf("Testing [ ft_link_items ]\n");
	printf("-FILLING THE 'CONTAINER'-\n	datas:\n");
	ft_link_items(&a, 10, argumentsover3);
	tmp = a;
	while (i < 9)
	{
		printf("	%d\n", tmp->data);
		tmp = tmp->next;
		i++;
	}
	printf("	After final iteration: %d (displays first value - circular linked list.)\n\n", tmp->data);


	//ft_lstnew();
	//ft_lstadd_back();
	//ft_tail_to_head();
	printf("Testing [ ft_free_items ]\n");
	printf("-FREEING THE 'CONTAINER'-\n");
	printf("	Pointer value before free: %p\n", a);
	ft_free_items(&a);
	printf("	Pointer value after free: %p\n\n", a);

	//ft_atoi();

	return 0;
}

int	test_swap()
{
	char		*args_a[5] = {"name", "1", "2", "4", "7"};
	char		*args_b[5] = {"name", "9", "15", "28", "42"};
	t_link		*a = NULL;
	t_link		*b = NULL;

	initialize_test_parameters(&a, args_a, 5);
	initialize_test_parameters(&b, args_b, 5);
	printf("-TESTING SWAP FUNCTIONS-\n");
	printf("	First value of A before swap:  %d\n", a->data);
	sa(&a);
	printf("	First value of A after swap:  %d\n\n", a->data);
	printf("	First value of B before swap:  %d\n", b->data);
	sb(&b);
	printf("	First value of B after swap:  %d\n\n", b->data);
	printf("	First value of A & B before 2nd swap:  %d  &  %d\n", a->data, b->data);
	ss(&a, &b);
	printf("	First value of A & B after 2nd swap:  %d  &  %d\n\n", a->data, b->data);
	ft_free_items(&a);
	ft_free_items(&b);
	return 0;
}

int	test_push()
{
	char		*args_a[5] = {"name", "1", "2", "4", "7"};
	char		*args_b[5] = {"name", "9", "15", "28", "42"};
	t_link		*b_empty = NULL;
	t_link		*a = NULL;
	t_link		*b = NULL;

	initialize_test_parameters(&a, args_a, 5);
	initialize_test_parameters(&b, args_b, 5);
	printf("-TESTING PUSH FUNCTIONS-.\n");
	printf("	First value of A before push to A:  %d\n", a->data);
	pa(&a, &b, NOT_FINAL);
	printf("	First value of A after push to A:  %d\n", a->data);
	printf("	First value of B after push to A and before push no.2 back to B:  %d\n\n", b->data);
	pb(&b, &a);
	printf("	First value of B after push back to B:  %d\n\n", b->data);
	printf("	First value of A & B before 3rd push:  %d  &  %d\n", a->data, b->data);
	pb(&b, &a);
	printf("	The top, tail and next of A after 3rd push: %d  %d  %d\n", a->data, a->previous->data, a->next->data);
	printf("	The top, tail and next of B after 3rd push: %d  %d  %d\n\n", b->data, b->previous->data, b->next->data);
	printf("	Empty stack B pointer before push to B: %p\n", b_empty);
	pb(&b_empty, &a);
	printf("	Previously empty B pointer after push to B: %p\n", b_empty);
	printf("	First value, tail and next of previously empty B before 2nd push:  %d  %d  %d\n", b_empty->data, b_empty->next->data, b_empty->previous->data);
	pb(&b_empty, &a);
	printf("	First val, next, next->next, and tail of previously empty B after 2nd push:  %d  %d  %d  %d\n\n", b_empty->data, b_empty->next->data, b_empty->next->next->data, b_empty->previous->data);

	ft_free_items(&a);
	ft_free_items(&b);
	ft_free_items(&b_empty);

	return 0;
}

int	test_rotate()
{
	char		*args_a[5] = {"name", "1", "2", "4", "7"};
	char		*args_b[5] = {"name", "9", "15", "28", "42"};
	t_link		*a = NULL;
	t_link		*b = NULL;

	initialize_test_parameters(&a, args_a, 5);
	initialize_test_parameters(&b, args_b, 5);

	printf("-TESTING ROTATION FUNCTIONS-\n");
	printf("Rotate A:\n");
	printf("A Head value and tail before RA:  %d  %d\n", a->data, a->previous->data);
	ra(&a);
	printf("A Head value and tail after RA:  %d  %d\n\n", a->data, a->previous->data);

	printf("Rotate B:\n");
	printf("B Head value and tail before RB:  %d  %d\n", b->data, b->previous->data);
	rb(&b);
	printf("B Head value and tail after RB:  %d  %d\n\n", b->data, b->previous->data);

	printf("Rotate both:\n");
	printf("Head values and tails before RR:  a-%d  b-%d  a-%d  b-%d\n", a->data, b->data, a->previous->data, b->previous->data);
	rr(&a, &b);
	printf("Head values and tails after RR:  a-%d  b-%d  a-%d  b-%d\n\n", a->data, b->data, a->previous->data, b->previous->data);

	ft_free_items(&a);
	ft_free_items(&b);

	return 0;
}

int	test_revrotate()
{
	char		*args_a[5] = {"name", "1", "2", "4", "7"};
	char		*args_b[5] = {"name", "9", "15", "28", "42"};
	t_link		*a = NULL;
	t_link		*b = NULL;

	initialize_test_parameters(&a, args_a, 5);
	initialize_test_parameters(&b, args_b, 5);

	printf("-TESTING REVERSE ROTATION FUNCTIONS-\n");
	printf("Reverse Rotate A:\n");
	printf("A Head value before RRA:  %d\n", a->data);
	rra(&a);
	printf("A Head value after RRA:  %d\n\n", a->data);

	printf("Reverse Rotate B:\n");
	printf("B Head value before RRB:  %d\n", b->data);
	rrb(&b);
	printf("B Head value after RRB:  %d \n\n", b->data);

	printf("Reverse Rotate both:\n");
	printf("Head values before RRR:  a-%d  b-%d\n", a->data, b->data);
	rrr(&a, &b);
	printf("Head values after RRR:  a-%d  b-%d\n\n", a->data, b->data);

	ft_free_items(&a);
	ft_free_items(&b);

	return 0;
}

