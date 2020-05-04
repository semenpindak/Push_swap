/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: semen <semen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/11 06:57:13 by semen             #+#    #+#             */
/*   Updated: 2020/04/16 12:53:23 by semen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_number **list_a, t_number **list_b)
{
	if ((*list_a)->next != NULL && (*list_b)->next != NULL)
	{
		*list_a = (*list_a)->next;
		*list_b = (*list_b)->next;
		ft_putstr("rr\n");
	}
}
