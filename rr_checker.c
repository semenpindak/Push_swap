/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oem <oem@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 00:22:23 by oem               #+#    #+#             */
/*   Updated: 2020/09/01 00:28:33 by oem              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_checker(t_number **list_a, t_number **list_b)
{
	if ((*list_a)->next != NULL && (*list_b)->next != NULL)
	{
		*list_a = (*list_a)->next;
		*list_b = (*list_b)->next;
	}
}
