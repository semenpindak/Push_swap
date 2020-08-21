/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_regular.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 17:19:14 by calpha            #+#    #+#             */
/*   Updated: 2020/08/21 19:38:18 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int count_list(t_number **list_b)
{
	int num;
	int count;

    num = (*list_b)->n;
	count = 0;
	while (*list_b)
	{
		if ((*list_b)->next != NULL)
			*list_b = (*list_b)->next;
		count++;
		if (num == (*list_b)->n)
			break;
	}
	return (count);
}

static int count_list_stack_a_status(t_number **list_a)
{
	int num;
	int count;

    num = (*list_a)->n;
	count = 0;
	while (*list_a)
	{
		if ((*list_a)->status == 1)
			count++;
		*list_a = (*list_a)->next;
		if (num == (*list_a)->n)
			break;
	}
	return (count);
}

// static int find_max_number(t_number **list_b)
// {
//     int max;
// 	int n;

//     max = (*list_b)->n;
//     n = (*list_b)->n;
//     while(*list_b)
//     {
// 		*list_b = (*list_b)->next;
//         if ((*list_b)->n > max)
//             max = (*list_b)->n;
//         if (n == (*list_b)->n)
//             break;
//     }
//     // printf("find_max_number_right = %d\n", max);
//     return (max);
// }



int	merge_sort_regular(t_number **list_a, t_number **list_b)
{
	int i = 0;
    int n;
	// int max = 0;
	int n_stack_a = 0;

	n = count_list(list_b);
	n_stack_a = count_list_stack_a_status(list_a);

	// printf("max = %d\n", max);
    //  printf("n = %d\n", n);
    //  show_me_two(list_a, list_b);
    while (n)
    {
		printf("начало цикла \n\n");
		if ((*list_a)->n > (*list_b)->n)
		{
			printf("начало 1иф \n\n");
			pa_three(&list_a, &list_b);
			n_stack_a++;
			show_me_two(list_a, list_b);
			i++;
			n--;
			// printf("1_if\n");
			// printf("n = %d\n", n);
			// usleep(3000000);
			printf("конец 1иф \n\n");
		}
		if ((*list_b) != NULL && ((*list_b)->n > (*list_a)->n))
		{
			printf("начало 2иф \n\n");
			ra_three(&list_a);
			show_me_two(list_a, list_b);
			i++;
			n_stack_a--;
			// printf("2_if\n");
			// usleep(3000000);
			printf("конец 2иф \n\n");
		}
		if (n_stack_a == 0)
		{
			while(n)
			{
				pa_three(&list_a, &list_b);
				i++;
				ra_three(&list_a);
				i++;
				show_me_two(list_a, list_b);
				n--;
			}
		}
		// if (((*list_b)->n - (*list_a)->n) == 1)
		// {
		// 	printf("начало 3иф \n\n");
		// 	ra_three(&list_a);
		// 	show_me_two(list_a, list_b);
		// 	i++;
		// 	pa_three(&list_a, &list_b);
		// 	show_me_two(list_a, list_b);
		// 	i++;
		// 	n--;
		// 	// printf("3_if\n");
		// 	// printf("n = %d\n", n);
		// 	// usleep(3000000);
		// 	printf("конец 3иф \n\n");
		// }

		printf("конец цикла \n\n");
		printf("n = %d, n_stack_a = %d \n\n", n, n_stack_a);
		// usleep(500000);
		if (n == 0)
			break;
	}
	return (i);
}
