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
	printf("");

	return 0;
}

void	initialize_test_parameters(t_link **a, char **args, int argc)
{
	ft_link_items(a, argc, args); //valgrind error.
}

int	test_primaries()
{
	//char	*argumentsover3[10] = {"name", "30", "1", "4", "42", "17", "7", "9", "2", "57"};
	//char	*arguments3[4] = {"name", "8", "2", "5"};
	//main_unit(10, argumentsover3);
	//main_unit(4, arguments3);


	//ft_sort();


	char	*short_args[4] = {"name", "8", "2", "5"};
	t_link	*a_short = NULL;
	int		res;

	initialize_test_parameters(&a_short, short_args, 4);
	printf("Testing [ ft_bubble ]\n");
	printf("-CHECKING WHETHER BUBBLE SORT WORKS-\n");
	printf("	Stack before bubble sort:\n");
	res = ft_is_sorted(&a_short);
	printf("		0 if unsorted: %d\n", res);
	ft_bubble(&a_short);
	printf("	Stack after bubble sort:\n");
	res = ft_is_sorted(&a_short);
	printf("		1 if sorted: %d\n\n", res);
	ft_free_items(&a_short);
	

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
	printf("-FILLING THE 'CONTAINER'-\n	Contents:\n");
	ft_link_items(&a, 10, argumentsover3);
	tmp = a;
	while (i < 9)
	{
		printf("	%d\n", tmp->content);
		tmp = tmp->next;
		i++;
	}
	printf("	After final iteration: %d (displays first value - circular linked list.)\n\n", tmp->content);


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
	printf("	First value of A before swap:  %d\n", a->content);
	sa(&a);
	printf("	First value of A after swap:  %d\n\n", a->content);
	printf("	First value of B before swap:  %d\n", b->content);
	sb(&b);
	printf("	First value of B after swap:  %d\n\n", b->content);
	printf("	First value of A & B before 2nd swap:  %d  &  %d\n", a->content, b->content);
	ss(&a, &b);
	printf("	First value of A & B after 2nd swap:  %d  &  %d\n\n", a->content, b->content);
	ft_free_items(&a);
	ft_free_items(&b);
	return 0;
}

int	test_push()
{
	printf("Test not implemented.\n");
	//pa();

	//pb();

	return 0;
}

int	test_rotate()
{
	printf("Test not implemented.\n");
	//ra();

	//rb();

	//rr();

	return 0;
}

int	test_revrotate()
{
	printf("Test not implemented.\n");
	//rra();

	//rrb();

	//rrr();

	return 0;
}

