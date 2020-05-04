/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 07:08:28 by semen             #+#    #+#             */
/*   Updated: 2020/04/16 12:56:41 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_number **list_a, t_number **list_b)
{
	if ((*list_a)->prev != NULL && (*list_b)->prev != NULL)
	{
		*list_a = (*list_a)->prev;
		*list_b = (*list_b)->prev;
		ft_putstr("rrr\n");
	}
}
