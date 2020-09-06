/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 06:57:13 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 09:09:26 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_num **list_a, t_num **list_b, t_key *bonus)
{
	if (*list_a && *list_b && (*list_a)->next != NULL && (*list_b)->next != NULL)
	{
		*list_a = (*list_a)->next;
		*list_b = (*list_b)->next;
		if (bonus->print == 1)
			ft_printf("rr\n");
	}
}
