/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:08:28 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 09:10:56 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_num **list_a, t_num **list_b, t_key *bonus)
{
	if (*list_a && *list_b && (*list_a)->prev != NULL && (*list_b)->prev != NULL)
	{
		*list_a = (*list_a)->prev;
		*list_b = (*list_b)->prev;
		if (bonus->print == 1)
			ft_printf("rrr\n");
	}
}
