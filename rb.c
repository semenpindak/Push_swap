/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 06:55:20 by semen             #+#    #+#             */
/*   Updated: 2020/09/05 09:08:49 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_num **list_b, t_key *bonus)
{
	if (*list_b && (*list_b)->next != NULL)
	{
		*list_b = (*list_b)->next;
		if (bonus->print == 1)
			ft_printf("rb\n");
	}
}
