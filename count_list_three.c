/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calpha <calpha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 19:43:56 by calpha            #+#    #+#             */
/*   Updated: 2020/08/24 21:14:33 by calpha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int count_list_three(t_number ***list_a)
{
	int num;
	int count;

	if (**list_a)
	{
		num = (**list_a)->n;
		count = 0;
		while (**list_a)
		{
			if ((**list_a)->next != NULL)
				**list_a = (**list_a)->next;
			count++;
			if (num == (**list_a)->n)
				break;
		}
		return (count);
	}
	return (0);
}
