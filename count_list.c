/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:14:29 by calpha            #+#    #+#             */
/*   Updated: 2020/09/03 17:24:58 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_list(t_num *list_a)
{
	int num;
	int count;

	if (list_a)
	{
		num = list_a->n;
		count = 0;
		while (list_a)
		{
			if (list_a->next != NULL)
				list_a = list_a->next;
			count++;
			if (num == list_a->n)
				break ;
		}
		return (count);
	}
	return (0);
}
