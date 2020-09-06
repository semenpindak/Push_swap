/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 00:01:01 by semen             #+#    #+#             */
/*   Updated: 2020/09/03 17:24:58 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mergesort_first(t_num **list_a, t_num **list_b, t_key *bonus)
{
	int n;

	n = count_list_two(list_b);
	while (n)
	{
		pa_three(&list_a, &list_b, bonus);
		debug_print_two(list_a, list_b, bonus);
		n--;
	}
}
