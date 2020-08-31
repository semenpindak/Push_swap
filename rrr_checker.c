/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:25:01 by oem               #+#    #+#             */
/*   Updated: 2020/09/01 00:26:37 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_checker(t_number **list_a, t_number **list_b)
{
	if ((*list_a)->prev != NULL && (*list_b)->prev != NULL)
	{
		*list_a = (*list_a)->prev;
		*list_b = (*list_b)->prev;
	}
}
