/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:01:01 by semen             #+#    #+#             */
/*   Updated: 2020/08/31 00:17:17 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_sort_first(t_number **list_a, t_number **list_b)
{
	int n;

	n = count_list_two(list_b);
	while (n)
	{
		pa_three(&list_a, &list_b);
		n--;
	}
}
